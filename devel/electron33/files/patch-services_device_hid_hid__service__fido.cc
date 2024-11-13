--- services/device/hid/hid_service_fido.cc.orig	2023-04-10 14:02:12 UTC
+++ services/device/hid/hid_service_fido.cc
@@ -0,0 +1,396 @@
+// Copyright 2014 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/hid/hid_service_fido.h"
+
+#include <fcntl.h>
+#include <poll.h>
+#include <stdint.h>
+
+#include <dlfcn.h>
+#include <fido.h>
+
+#include <limits>
+#include <memory>
+#include <string>
+#include <utility>
+
+#include "base/files/file.h"
+#include "base/files/file_path.h"
+#include "base/files/file_util.h"
+#include "base/files/scoped_file.h"
+#include "base/location.h"
+#include "base/sequence_checker.h"
+#include "base/strings/string_number_conversions.h"
+#include "base/strings/string_split.h"
+#include "base/strings/string_util.h"
+#include "base/task/sequenced_task_runner.h"
+#include "base/task/thread_pool.h"
+#include "base/threading/scoped_blocking_call.h"
+#include "build/build_config.h"
+#include "build/chromeos_buildflags.h"
+#include "components/device_event_log/device_event_log.h"
+#include "device/udev_linux/scoped_udev.h"
+#include "device/udev_linux/udev_watcher.h"
+#include "services/device/hid/hid_connection_fido.h"
+
+namespace device {
+
+namespace {
+
+bool terrible_ping_kludge(int fd, const std::string &path) {
+  u_char data[256];
+  int i, n;
+  struct pollfd pfd;
+
+  for (i = 0; i < 4; i++) {
+    memset(data, 0, sizeof(data));
+    /* broadcast channel ID */
+    data[1] = 0xff;
+    data[2] = 0xff;
+    data[3] = 0xff;
+    data[4] = 0xff;
+    /* Ping command */
+    data[5] = 0x81;
+    /* One byte ping only, Vasili */
+    data[6] = 0;   
+    data[7] = 1;   
+    HID_LOG(EVENT) << "send ping " << i << " " << path;
+    if (write(fd, data, 64) == -1) {
+      HID_PLOG(ERROR) << "write " << path;
+      return false;
+    }
+    HID_LOG(EVENT) << "wait reply " << path;
+    memset(&pfd, 0, sizeof(pfd));
+    pfd.fd = fd; 
+    pfd.events = POLLIN;
+    if ((n = poll(&pfd, 1, 100)) == -1) {
+      HID_PLOG(EVENT) << "poll " << path;
+      return false;
+    } else if (n == 0) {
+      HID_LOG(EVENT) << "timed out " << path;
+      continue;
+    }
+    if (read(fd, data, 64) == -1) {  
+      HID_PLOG(ERROR) << "read " << path;
+      return false;
+    }
+    /*
+     * Ping isn't always supported on the broadcast channel,
+     * so we might get an error, but we don't care - we're
+     * synched now.
+     */
+    HID_LOG(EVENT) << "got reply " << path;
+    return true;
+  }
+  HID_LOG(ERROR) << "no response " << path;
+  return false;
+}
+
+// HID report descriptor for U2F interface. Copied from:
+// https://chromium.googlesource.com/chromiumos/platform2/+/c6c7e4e54fce11932fedaa3ea10236bf75d85a2b%5E%21/u2fd/u2fhid.cc
+// Apparently Chromium wants to see these bytes, but OpenBSD fido(4)
+// devices prohibit USB_GET_REPORT_DESC ioctl that could be used to
+// get the bytes from the USB device.
+constexpr uint8_t kU2fReportDesc[] = {
+    0x06, 0xD0, 0xF1, /* Usage Page (FIDO Alliance), FIDO_USAGE_PAGE */
+    0x09, 0x01,       /* Usage (U2F HID Auth. Device) FIDO_USAGE_U2FHID */
+    0xA1, 0x01,       /* Collection (Application), HID_APPLICATION */
+    0x09, 0x20,       /*  Usage (Input Report Data), FIDO_USAGE_DATA_IN */
+    0x15, 0x00,       /*  Logical Minimum (0) */
+    0x26, 0xFF, 0x00, /*  Logical Maximum (255) */
+    0x75, 0x08,       /*  Report Size (8) */
+    0x95, 0x40,       /*  Report Count (64), HID_INPUT_REPORT_BYTES */
+    0x81, 0x02,       /*  Input (Data, Var, Abs), Usage */
+    0x09, 0x21,       /*  Usage (Output Report Data), FIDO_USAGE_DATA_OUT */
+    0x15, 0x00,       /*  Logical Minimum (0) */
+    0x26, 0xFF, 0x00, /*  Logical Maximum (255) */
+    0x75, 0x08,       /*  Report Size (8) */
+    0x95, 0x40,       /*  Report Count (64), HID_OUTPUT_REPORT_BYTES */
+    0x91, 0x02,       /*  Output (Data, Var, Abs), Usage */
+    0xC0              /* End Collection */
+};
+
+}  // namespace
+
+struct HidServiceFido::ConnectParams {
+  ConnectParams(scoped_refptr<HidDeviceInfo> device_info,
+                bool allow_protected_reports,
+                bool allow_fido_reports,
+                ConnectCallback callback)
+      : device_info(std::move(device_info)),
+        allow_protected_reports(allow_protected_reports),
+        allow_fido_reports(allow_fido_reports),
+        callback(std::move(callback)),
+	task_runner(base::SequencedTaskRunner::GetCurrentDefault()),
+        blocking_task_runner(
+            base::ThreadPool::CreateSequencedTaskRunner(kBlockingTaskTraits)) {}
+  ~ConnectParams() {}
+
+  scoped_refptr<HidDeviceInfo> device_info;
+  bool allow_protected_reports;
+  bool allow_fido_reports;
+  ConnectCallback callback;
+  scoped_refptr<base::SequencedTaskRunner> task_runner;
+  scoped_refptr<base::SequencedTaskRunner> blocking_task_runner;
+  base::ScopedFD fd;
+};
+
+class HidServiceFido::BlockingTaskRunnerHelper : public UdevWatcher::Observer {
+ public:
+  BlockingTaskRunnerHelper(base::WeakPtr<HidServiceFido> service)
+      : service_(std::move(service)),
+        task_runner_(base::SequencedTaskRunner::GetCurrentDefault()) {
+    DETACH_FROM_SEQUENCE(sequence_checker_);
+  }
+
+  BlockingTaskRunnerHelper(const BlockingTaskRunnerHelper&) = delete;
+  BlockingTaskRunnerHelper& operator=(const BlockingTaskRunnerHelper&) = delete;
+
+  ~BlockingTaskRunnerHelper() override {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+  }
+
+  void Start() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+    void *library = dlopen("libudev.so", RTLD_NOW | RTLD_LOCAL);
+    if (library) {
+      dlclose(library);
+      watcher_ = UdevWatcher::StartWatching(this);
+      watcher_->EnumerateExistingDevices();
+    } else {
+      HID_LOG(ERROR) << "No udev available, failling back to single enumeration";
+      WalkFidoDevices(nullptr);
+    }
+
+    task_runner_->PostTask(
+        FROM_HERE,
+        base::BindOnce(&HidServiceFido::FirstEnumerationComplete, service_));
+  }
+
+ private:
+  void WalkFidoDevices(const char *name) {
+    fido_dev_info_t *devlist = NULL;
+    fido_dev_t *dev = NULL;
+    size_t devlist_len = 0, i;
+    const char *path;
+    int r;
+    const int MAX_FIDO_DEVICES = 256;
+
+    if ((devlist = fido_dev_info_new(MAX_FIDO_DEVICES)) == NULL) {
+      HID_LOG(ERROR) << "fido_dev_info_new failed";
+      goto out;
+    }
+    if ((r = fido_dev_info_manifest(devlist, MAX_FIDO_DEVICES, &devlist_len)) !=
+        FIDO_OK) {
+      HID_LOG(ERROR) << "fido_dev_info_manifest: " << fido_strerr(r);
+      goto out;
+    }
+
+    HID_LOG(EVENT) << "fido_dev_info_manifest found " << devlist_len
+                   << " device(s)";
+
+    for (i = 0; i < devlist_len; i++) {
+      const fido_dev_info_t *di = fido_dev_info_ptr(devlist, i);
+
+      if (di == NULL) {
+        HID_LOG(ERROR) << "fido_dev_info_ptr " << i << " failed";
+        continue;
+      }
+
+      if ((path = fido_dev_info_path(di)) == NULL) {
+        HID_LOG(ERROR) << "fido_dev_info_path " << i << " failed";
+        continue;
+      }
+
+      if (name != nullptr && !strcmp(path, name)) {
+        HID_LOG(EVENT) << "hotplug device " << i << ": " << path;
+        OnFidoDeviceAdded(di);
+        break;
+      }
+
+      HID_LOG(EVENT) << "trying device " << i << ": " << path;
+      if ((dev = fido_dev_new()) == NULL) {
+        HID_LOG(ERROR) << "fido_dev_new failed";
+        continue;
+      }
+
+      if ((r = fido_dev_open(dev, path)) != FIDO_OK) {
+        HID_LOG(ERROR) << "fido_dev_open failed " << path;
+        fido_dev_free(&dev);
+        continue;
+      }
+
+      fido_dev_close(dev);
+      fido_dev_free(&dev);
+
+      OnFidoDeviceAdded(di);
+    }
+  out:
+    if (devlist != NULL)
+      fido_dev_info_free(&devlist, MAX_FIDO_DEVICES);
+  }
+
+  void OnFidoDeviceAdded(const fido_dev_info_t *di) {
+    auto null_as_empty = [](const char *r) -> std::string {
+      return (r != nullptr) ? r : "";
+    };
+    std::string device_node(null_as_empty(fido_dev_info_path(di)));  
+    std::vector<uint8_t> report_descriptor(
+        kU2fReportDesc, kU2fReportDesc + sizeof(kU2fReportDesc));
+
+    auto device_info = base::MakeRefCounted<HidDeviceInfo>(
+        device_node, /*physical_device_id*/"", fido_dev_info_vendor(di),
+        fido_dev_info_product(di), null_as_empty(fido_dev_info_product_string(di)),
+        null_as_empty(fido_dev_info_manufacturer_string(di)),
+	device::mojom::HidBusType::kHIDBusTypeUSB, report_descriptor,
+        device_node);
+
+    task_runner_->PostTask(
+        FROM_HERE,
+        base::BindOnce(&HidServiceFido::AddDevice, service_, device_info));
+  }
+
+  // UdevWatcher::Observer
+  void OnDeviceAdded(ScopedUdevDevicePtr device) override {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+
+    const char* subsystem = udev_device_get_subsystem(device.get());
+    if (!subsystem || strcmp(subsystem, "fido") != 0)
+      return;
+
+    const char* device_path = udev_device_get_syspath(device.get());
+    if (!device_path)
+      return;
+
+    WalkFidoDevices(device_path);
+  }
+
+  void OnDeviceRemoved(ScopedUdevDevicePtr device) override {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+
+    const char* device_path = udev_device_get_syspath(device.get());
+    if (device_path) {
+      task_runner_->PostTask(
+          FROM_HERE, base::BindOnce(&HidServiceFido::RemoveDevice, service_,
+                                    std::string(device_path)));
+    }
+  }
+
+  void OnDeviceChanged(ScopedUdevDevicePtr) override {}
+
+  SEQUENCE_CHECKER(sequence_checker_);
+  std::unique_ptr<UdevWatcher> watcher_;
+
+  // This weak pointer is only valid when checked on this task runner.
+  base::WeakPtr<HidServiceFido> service_;
+  scoped_refptr<base::SequencedTaskRunner> task_runner_;
+};
+
+HidServiceFido::HidServiceFido()
+    : blocking_task_runner_(
+          base::ThreadPool::CreateSequencedTaskRunner(kBlockingTaskTraits)),
+      helper_(nullptr, base::OnTaskRunnerDeleter(blocking_task_runner_)) {
+  // We need to properly initialize |blocking_task_helper_| here because we need
+  // |weak_factory_| to be created first.
+  helper_.reset(new BlockingTaskRunnerHelper(weak_factory_.GetWeakPtr()));
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskRunnerHelper::Start,
+                                base::Unretained(helper_.get())));
+}
+
+HidServiceFido::~HidServiceFido() = default;
+
+base::WeakPtr<HidService> HidServiceFido::GetWeakPtr() {
+  return weak_factory_.GetWeakPtr();
+}
+
+void HidServiceFido::Connect(const std::string& device_guid,
+                              bool allow_protected_reports,
+                              bool allow_fido_reports,
+                              ConnectCallback callback) {
+  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+  const auto& map_entry = devices().find(device_guid);
+  if (map_entry == devices().end()) {
+    base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
+        FROM_HERE, base::BindOnce(std::move(callback), nullptr));
+    return;
+  }
+  scoped_refptr<HidDeviceInfo> device_info = map_entry->second;
+
+  auto params =
+      std::make_unique<ConnectParams>(device_info, allow_protected_reports,
+                                      allow_fido_reports, std::move(callback));
+  scoped_refptr<base::SequencedTaskRunner> blocking_task_runner =
+      params->blocking_task_runner;
+  blocking_task_runner->PostTask(
+      FROM_HERE, base::BindOnce(&HidServiceFido::OpenOnBlockingThread,
+                                std::move(params)));
+}
+
+// static
+void HidServiceFido::OpenOnBlockingThread(
+    std::unique_ptr<ConnectParams> params) {
+  base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
+                                                base::BlockingType::MAY_BLOCK);
+  scoped_refptr<base::SequencedTaskRunner> task_runner = params->task_runner;
+
+  base::FilePath device_path(params->device_info->device_node());
+  base::File device_file;
+  int flags =
+      base::File::FLAG_OPEN | base::File::FLAG_READ | base::File::FLAG_WRITE;
+  device_file.Initialize(device_path, flags);
+  if (!device_file.IsValid()) {
+    base::File::Error file_error = device_file.error_details();
+
+    if (file_error == base::File::FILE_ERROR_ACCESS_DENIED) {
+      HID_LOG(EVENT)
+          << "Access denied opening device read-write, trying read-only.";
+      flags = base::File::FLAG_OPEN | base::File::FLAG_READ;
+      device_file.Initialize(device_path, flags);
+    }
+  }
+  if (!device_file.IsValid()) {
+    HID_LOG(EVENT) << "Failed to open '" << params->device_info->device_node()
+                   << "': "
+                   << base::File::ErrorToString(device_file.error_details());
+    task_runner->PostTask(FROM_HERE,
+                          base::BindOnce(std::move(params->callback), nullptr));
+    return;
+  }
+  if (!terrible_ping_kludge(device_file.GetPlatformFile(), params->device_info->device_node())) {
+    HID_LOG(EVENT) << "Failed to ping " << params->device_info->device_node();
+    task_runner->PostTask(FROM_HERE, base::BindOnce(std::move(params->callback), nullptr));
+    return;
+  }
+  params->fd.reset(device_file.TakePlatformFile());
+
+  task_runner->PostTask(FROM_HERE, base::BindOnce(&HidServiceFido::FinishOpen,
+                                                  std::move(params)));
+}
+
+// static
+void HidServiceFido::FinishOpen(std::unique_ptr<ConnectParams> params) {
+  DCHECK(params->fd.is_valid());
+
+  if (!base::SetNonBlocking(params->fd.get())) {
+    HID_PLOG(DEBUG) << "Failed to set the non-blocking flag on the device fd";
+    std::move(params->callback).Run(nullptr);
+    return;
+  }
+
+  std::move(params->callback)
+      .Run(base::MakeRefCounted<HidConnectionFido>(
+          std::move(params->device_info), std::move(params->fd),
+          std::move(params->blocking_task_runner),
+          params->allow_protected_reports, params->allow_fido_reports));
+}
+
+}  // namespace device
