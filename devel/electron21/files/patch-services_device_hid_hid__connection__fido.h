--- services/device/hid/hid_connection_fido.h.orig	2022-02-07 13:39:41 UTC
+++ services/device/hid/hid_connection_fido.h
@@ -0,0 +1,57 @@
+// Copyright (c) 2020 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef SERVICE_DEVICE_HID_HID_CONNECTION_FIDO_H_
+#define SERVICE_DEVICE_HID_HID_CONNECTION_FIDO_H_
+
+#include "base/files/scoped_file.h"
+#include "base/memory/ptr_util.h"
+#include "base/memory/ref_counted_memory.h"
+#include "base/memory/weak_ptr.h"
+#include "base/sequence_checker.h"
+#include "services/device/hid/hid_connection.h"
+
+namespace device {
+
+class HidConnectionFido : public HidConnection {
+public:
+  HidConnectionFido(
+      scoped_refptr<HidDeviceInfo> device_info, base::ScopedFD fd,
+      scoped_refptr<base::SequencedTaskRunner> blocking_task_runner,
+      bool allow_protected_reports, bool allow_fido_reports);
+
+private:
+  friend class base::RefCountedThreadSafe<HidConnectionFido>;
+  class BlockingTaskHelper;
+
+  HidConnectionFido(const HidConnectionFido&) = delete;
+  HidConnectionFido& operator=(const HidConnectionFido&) = delete;
+
+  ~HidConnectionFido() override;
+
+  // HidConnection implementation.
+  void PlatformClose() override;
+  void PlatformWrite(scoped_refptr<base::RefCountedBytes> buffer,
+                     WriteCallback callback) override;
+  void PlatformGetFeatureReport(uint8_t report_id,
+                                ReadCallback callback) override;
+  void PlatformSendFeatureReport(scoped_refptr<base::RefCountedBytes> buffer,
+                                 WriteCallback callback) override;
+
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
+
+  SEQUENCE_CHECKER(sequence_checker_);
+
+  base::WeakPtrFactory<HidConnectionFido> weak_factory_;
+
+  // |helper_| lives on the sequence to which |blocking_task_runner_| posts
+  // tasks so all calls must be posted there including this object's
+  // destruction.
+  std::unique_ptr<BlockingTaskHelper> helper_;
+};
+
+} // namespace device
+
+#endif // SERVICE_DEVICE_HID_HID_CONNECTION_FIDO_H_
