--- services/device/hid/hid_connection_freebsd.cc.orig	2019-09-16 09:25:15 UTC
+++ services/device/hid/hid_connection_freebsd.cc
@@ -0,0 +1,240 @@
+// Copyright (c) 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/hid/hid_connection_freebsd.h"
+
+#include <dev/usb/usbhid.h>
+#include <dev/usb/usb_ioctl.h>
+
+#include "base/bind.h"
+#include "base/files/file_descriptor_watcher_posix.h"
+#include "base/location.h"
+#include "base/numerics/safe_math.h"
+#include "base/posix/eintr_wrapper.h"
+#include "base/single_thread_task_runner.h"
+#include "base/strings/stringprintf.h"
+#include "base/task/post_task.h"
+#include "base/threading/scoped_blocking_call.h"
+#include "base/threading/thread_restrictions.h"
+#include "base/threading/thread_task_runner_handle.h"
+#include "components/device_event_log/device_event_log.h"
+#include "services/device/hid/hid_service.h"
+
+namespace device {
+
+class HidConnectionFreeBSD::BlockingTaskHelper {
+ public:
+  BlockingTaskHelper(base::ScopedFD fd,
+                     scoped_refptr<HidDeviceInfo> device_info,
+                     base::WeakPtr<HidConnectionFreeBSD> connection)
+      : fd_(std::move(fd)),
+        connection_(connection),
+        origin_task_runner_(base::ThreadTaskRunnerHandle::Get()) {
+    DETACH_FROM_SEQUENCE(sequence_checker_);
+    // Report buffers must always have room for the report ID.
+    report_buffer_size_ = device_info->max_input_report_size() + 1;
+    has_report_id_ = device_info->has_report_id();
+  }
+
+  ~BlockingTaskHelper() { DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_); }
+
+  // Starts the FileDescriptorWatcher that reads input events from the device.
+  // Must be called on a thread that has a base::MessageLoopForIO.
+  void Start() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::internal::AssertBlockingAllowed();
+
+    file_watcher_ = base::FileDescriptorWatcher::WatchReadable(
+        fd_.get(), base::Bind(&BlockingTaskHelper::OnFileCanReadWithoutBlocking,
+                              base::Unretained(this)));
+  }
+
+  void Write(scoped_refptr<base::RefCountedBytes> buffer,
+             WriteCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+
+    auto data = buffer->front();
+    size_t size = buffer->size();
+    // if report id is 0, it shouldn't be included
+    if (data[0] == 0) {
+      data++;
+      size--;
+    }
+
+    ssize_t result = HANDLE_EINTR(write(fd_.get(), data, size));
+    if (result < 0) {
+      HID_PLOG(EVENT) << "Write failed";
+      origin_task_runner_->PostTask(FROM_HERE, base::BindOnce(std::move(callback), false));
+    } else {
+      if (static_cast<size_t>(result) != size)
+        HID_LOG(EVENT) << "Incomplete HID write: " << result << " != " << size;
+      origin_task_runner_->PostTask(FROM_HERE, base::BindOnce(std::move(callback), true));
+    }
+  }
+
+  void GetFeatureReport(uint8_t report_id,
+                        scoped_refptr<base::RefCountedBytes> buffer,
+                        ReadCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+    struct usb_gen_descriptor ugd;
+    ugd.ugd_report_type = UHID_FEATURE_REPORT;
+    ugd.ugd_data = buffer->front();
+    ugd.ugd_maxlen = buffer->size();
+    int result = HANDLE_EINTR(
+        ioctl(fd_.get(), USB_GET_REPORT, &ugd));
+    if (result < 0) {
+      HID_PLOG(EVENT) << "Failed to get feature report";
+      origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), false, nullptr, 0));
+    } else if (result == 0) {
+      HID_LOG(EVENT) << "Get feature result too short.";
+      origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), false, nullptr, 0));
+    } else {
+      origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), true, buffer, result));
+    }
+  }
+
+  void SendFeatureReport(scoped_refptr<base::RefCountedBytes> buffer,
+                         WriteCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    struct usb_gen_descriptor ugd;
+    ugd.ugd_report_type = UHID_FEATURE_REPORT;
+    ugd.ugd_data = buffer->front();
+    ugd.ugd_maxlen = buffer->size();
+    // FreeBSD does not require report id if it's not used
+    if (buffer->front()[0] == 0) {
+      ugd.ugd_data = buffer->front() + 1;
+      ugd.ugd_maxlen = buffer->size() - 1;
+    } else {
+      ugd.ugd_data = buffer->front();
+      ugd.ugd_maxlen = buffer->size();
+    }
+    int result = HANDLE_EINTR(
+        ioctl(fd_.get(), USB_SET_REPORT, &ugd));
+    if (result < 0) {
+      HID_PLOG(EVENT) << "Failed to send feature report";
+      origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), false));
+    } else {
+      origin_task_runner_->PostTask(FROM_HERE,
+                                    base::BindOnce(std::move(callback), true));
+    }
+  }
+
+ private:
+  void OnFileCanReadWithoutBlocking() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+    scoped_refptr<base::RefCountedBytes> buffer(new base::RefCountedBytes(report_buffer_size_));
+    unsigned char* data = buffer->front();
+    size_t length = report_buffer_size_;
+    if (!has_report_id_) {
+      // FreeBSD will not prefix the buffer with a report ID if report IDs are not
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
+        FROM_HERE, base::BindOnce(&HidConnectionFreeBSD::ProcessInputReport,
+                              connection_, buffer, bytes_read));
+  }
+
+  SEQUENCE_CHECKER(sequence_checker_);
+  base::ScopedFD fd_;
+  size_t report_buffer_size_;
+  bool has_report_id_;
+  base::WeakPtr<HidConnectionFreeBSD> connection_;
+  const scoped_refptr<base::SequencedTaskRunner> origin_task_runner_;
+  std::unique_ptr<base::FileDescriptorWatcher::Controller> file_watcher_;
+
+  DISALLOW_COPY_AND_ASSIGN(BlockingTaskHelper);
+};
+
+HidConnectionFreeBSD::HidConnectionFreeBSD(
+    scoped_refptr<HidDeviceInfo> device_info,
+    base::ScopedFD fd,
+    scoped_refptr<base::SequencedTaskRunner> blocking_task_runner)
+    : HidConnection(device_info),
+      blocking_task_runner_(std::move(blocking_task_runner)),
+      weak_factory_(this) {
+  helper_ = std::make_unique<BlockingTaskHelper>(std::move(fd), device_info,
+                                                 weak_factory_.GetWeakPtr());
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskHelper::Start,
+                                base::Unretained(helper_.get())));
+}
+
+HidConnectionFreeBSD::~HidConnectionFreeBSD() {}
+
+void HidConnectionFreeBSD::PlatformClose() {
+  // By closing the device on the blocking task runner 1) the requirement that
+  // base::ScopedFD is destroyed on a thread where I/O is allowed is satisfied
+  // and 2) any tasks posted to this task runner that refer to this file will
+  // complete before it is closed.
+  blocking_task_runner_->DeleteSoon(FROM_HERE, helper_.release());
+}
+
+void HidConnectionFreeBSD::PlatformWrite(scoped_refptr<base::RefCountedBytes> buffer,
+                                     WriteCallback callback) {
+
+  blocking_task_runner_->PostTask(
+      FROM_HERE,
+      base::BindOnce(&BlockingTaskHelper::Write, base::Unretained(helper_.get()),
+                 buffer, std::move(callback)));
+}
+
+void HidConnectionFreeBSD::PlatformGetFeatureReport(uint8_t report_id,
+                                                ReadCallback callback) {
+  // The first byte of the destination buffer is the report ID being requested
+  // and is overwritten by the feature report.
+  DCHECK_GT(device_info()->max_feature_report_size(), 0u);
+  scoped_refptr<base::RefCountedBytes> buffer(
+      new base::RefCountedBytes(device_info()->max_feature_report_size() + 1));
+  if (report_id != 0)
+    buffer->data()[0] = report_id;
+
+  blocking_task_runner_->PostTask(
+      FROM_HERE,
+      base::BindOnce(&BlockingTaskHelper::GetFeatureReport,
+                 base::Unretained(helper_.get()), report_id,
+                 buffer, std::move(callback)));
+}
+
+void HidConnectionFreeBSD::PlatformSendFeatureReport(
+    scoped_refptr<base::RefCountedBytes> buffer,
+    WriteCallback callback) {
+  base::ScopedBlockingCall scoped_blocking_call(
+      FROM_HERE, base::BlockingType::MAY_BLOCK);
+  blocking_task_runner_->PostTask(
+      FROM_HERE,
+      base::BindOnce(&BlockingTaskHelper::SendFeatureReport,
+                 base::Unretained(helper_.get()), buffer, std::move(callback)));
+}
+
+}  // namespace device
