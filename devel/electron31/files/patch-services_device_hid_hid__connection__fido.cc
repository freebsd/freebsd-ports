--- services/device/hid/hid_connection_fido.cc.orig	2024-06-30 11:49:03 UTC
+++ services/device/hid/hid_connection_fido.cc
@@ -0,0 +1,216 @@
+// Copyright 2014 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/hid/hid_connection_fido.h"
+
+#include <errno.h>
+#include <sys/ioctl.h>
+
+#include <memory>
+#include <string>
+#include <utility>
+
+#include "base/files/file_descriptor_watcher_posix.h"
+#include "base/memory/ref_counted_memory.h"
+#include "base/posix/eintr_wrapper.h"
+#include "base/threading/scoped_blocking_call.h"
+#include "components/device_event_log/device_event_log.h"
+#include "services/device/hid/hid_service.h"
+
+namespace device {
+
+class HidConnectionFido::BlockingTaskRunnerHelper {
+ public:
+  BlockingTaskRunnerHelper(base::ScopedFD fd,
+                           scoped_refptr<HidDeviceInfo> device_info,
+                           base::WeakPtr<HidConnectionFido> connection)
+      : fd_(std::move(fd)),
+        connection_(connection),
+        origin_task_runner_(base::SequencedTaskRunner::GetCurrentDefault()) {
+    DETACH_FROM_SEQUENCE(sequence_checker_);
+    // Report buffers must always have room for the report ID.
+    report_buffer_size_ = device_info->max_input_report_size() + 1;
+    has_report_id_ = device_info->has_report_id();
+  }
+
+  BlockingTaskRunnerHelper(const BlockingTaskRunnerHelper&) = delete;
+  BlockingTaskRunnerHelper& operator=(const BlockingTaskRunnerHelper&) = delete;
+
+  ~BlockingTaskRunnerHelper() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+  }
+
+  // Starts the FileDescriptorWatcher that reads input events from the device.
+  // Must be called on a thread that has a base::MessageLoopForIO.
+  void Start() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+    file_watcher_ = base::FileDescriptorWatcher::WatchReadable(
+        fd_.get(), base::BindRepeating(
+                       &BlockingTaskRunnerHelper::OnFileCanReadWithoutBlocking,
+                       base::Unretained(this)));
+  }
+
+  void Write(scoped_refptr<base::RefCountedBytes> buffer,
+             WriteCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+
+    auto data = buffer->data();
+    size_t size = buffer->size();
+    // if report id is 0, it shouldn't be included
+    if (data[0] == 0) {
+      data++;
+      size--;
+    }
+
+    ssize_t result =
+        HANDLE_EINTR(write(fd_.get(), data, size));
+    if (result < 0) {
+      HID_PLOG(EVENT) << "Write failed";
+      origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), false));
+    } else {
+      if (static_cast<size_t>(result) != size) {
+        HID_LOG(EVENT) << "Incomplete HID write: " << result
+                       << " != " << buffer->size();
+      }
+      origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), true));
+    }
+  }
+
+  void GetFeatureReport(uint8_t report_id,
+                        scoped_refptr<base::RefCountedBytes> buffer,
+                        ReadCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+    HID_PLOG(EVENT) << "GendFeatureReport not implemented on OpenBSD";
+    origin_task_runner_->PostTask(
+        FROM_HERE, base::BindOnce(std::move(callback), false, nullptr, 0));
+  }
+
+  void SendFeatureReport(scoped_refptr<base::RefCountedBytes> buffer,
+                         WriteCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+    HID_PLOG(EVENT) << "SendFeatureReport not implemented on OpenBSD";
+    origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), false));
+  }
+
+ private:
+  void OnFileCanReadWithoutBlocking() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+    auto buffer =
+        base::MakeRefCounted<base::RefCountedBytes>(report_buffer_size_);
+    uint8_t* data = buffer->as_vector().data();
+    size_t length = report_buffer_size_;
+    if (!has_report_id_) {
+      // Fido will not prefix the buffer with a report ID if report IDs are not
+      // used by the device. Prefix the buffer with 0.
+      *data++ = 0;
+      length--;
+    }
+
+    ssize_t bytes_read = HANDLE_EINTR(read(fd_.get(), data, length));
+    if (bytes_read < 0) {
+      if (errno != EAGAIN) {
+        HID_PLOG(EVENT) << "Read failed";
+        // This assumes that the error is unrecoverable and disables reading
+        // from the device until it has been re-opened.
+        // TODO(reillyg): Investigate starting and stopping the file descriptor
+        // watcher in response to pending read requests so that per-request
+        // errors can be returned to the client.
+        file_watcher_.reset();
+      }
+      return;
+    }
+    if (!has_report_id_) {
+      // Behave as if the byte prefixed above as the the report ID was read.
+      bytes_read++;
+    }
+
+    origin_task_runner_->PostTask(
+        FROM_HERE, base::BindOnce(&HidConnectionFido::ProcessInputReport,
+                                  connection_, buffer, bytes_read));
+  }
+
+  SEQUENCE_CHECKER(sequence_checker_);
+  base::ScopedFD fd_;
+  size_t report_buffer_size_;
+  bool has_report_id_;
+  base::WeakPtr<HidConnectionFido> connection_;
+  const scoped_refptr<base::SequencedTaskRunner> origin_task_runner_;
+  std::unique_ptr<base::FileDescriptorWatcher::Controller> file_watcher_;
+};
+
+HidConnectionFido::HidConnectionFido(
+    scoped_refptr<HidDeviceInfo> device_info,
+    base::ScopedFD fd,
+    scoped_refptr<base::SequencedTaskRunner> blocking_task_runner,
+    bool allow_protected_reports,
+    bool allow_fido_reports)
+    : HidConnection(device_info, allow_protected_reports, allow_fido_reports),
+      helper_(nullptr, base::OnTaskRunnerDeleter(blocking_task_runner)),
+      blocking_task_runner_(std::move(blocking_task_runner)) {
+  helper_.reset(new BlockingTaskRunnerHelper(std::move(fd), device_info,
+                                             weak_factory_.GetWeakPtr()));
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskRunnerHelper::Start,
+                                base::Unretained(helper_.get())));
+}
+
+HidConnectionFido::~HidConnectionFido() {}
+
+void HidConnectionFido::PlatformClose() {
+  // By closing the device on the blocking task runner 1) the requirement that
+  // base::ScopedFD is destroyed on a thread where I/O is allowed is satisfied
+  // and 2) any tasks posted to this task runner that refer to this file will
+  // complete before it is closed.
+  helper_.reset();
+}
+
+void HidConnectionFido::PlatformWrite(
+    scoped_refptr<base::RefCountedBytes> buffer,
+    WriteCallback callback) {
+  // Fido expects the first byte of the buffer to always be a report ID so the
+  // buffer can be used directly.
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskRunnerHelper::Write,
+                                base::Unretained(helper_.get()), buffer,
+                                std::move(callback)));
+}
+
+void HidConnectionFido::PlatformGetFeatureReport(uint8_t report_id,
+                                                  ReadCallback callback) {
+  // The first byte of the destination buffer is the report ID being requested
+  // and is overwritten by the feature report.
+  DCHECK_GT(device_info()->max_feature_report_size(), 0u);
+  auto buffer = base::MakeRefCounted<base::RefCountedBytes>(
+      device_info()->max_feature_report_size() + 1);
+  buffer->as_vector().data()[0] = report_id;
+
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskRunnerHelper::GetFeatureReport,
+                                base::Unretained(helper_.get()), report_id,
+                                buffer, std::move(callback)));
+}
+
+void HidConnectionFido::PlatformSendFeatureReport(
+    scoped_refptr<base::RefCountedBytes> buffer,
+    WriteCallback callback) {
+  // Fido expects the first byte of the buffer to always be a report ID so the
+  // buffer can be used directly.
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskRunnerHelper::SendFeatureReport,
+                                base::Unretained(helper_.get()), buffer,
+                                std::move(callback)));
+}
+
+}  // namespace device
