--- services/device/hid/hid_connection_freebsd.h.orig	2019-12-16 13:33:58 UTC
+++ services/device/hid/hid_connection_freebsd.h
@@ -0,0 +1,68 @@
+// Copyright (c) 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_CONNECTION_FREEBSD_H_
+#define DEVICE_HID_HID_CONNECTION_FREEBSD_H_
+
+#include <stddef.h>
+#include <stdint.h>
+
+#include "base/files/scoped_file.h"
+#include "base/macros.h"
+#include "base/memory/ptr_util.h"
+#include "base/memory/ref_counted_memory.h"
+#include "base/memory/weak_ptr.h"
+#include "base/sequence_checker.h"
+#include "services/device/hid/hid_connection.h"
+
+namespace base {
+class SequencedTaskRunner;
+}
+
+namespace net {
+class IOBuffer;
+}
+
+namespace device {
+
+class HidConnectionFreeBSD : public HidConnection {
+ public:
+  HidConnectionFreeBSD(
+      scoped_refptr<HidDeviceInfo> device_info,
+      base::ScopedFD fd,
+      scoped_refptr<base::SequencedTaskRunner> blocking_task_runner);
+
+ private:
+  friend class base::RefCountedThreadSafe<HidConnectionFreeBSD>;
+  class BlockingTaskHelper;
+
+  ~HidConnectionFreeBSD() override;
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
+  // |helper_| lives on the sequence to which |blocking_task_runner_| posts
+  // tasks so all calls must be posted there including this object's
+  // destruction.
+  std::unique_ptr<BlockingTaskHelper> helper_;
+
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
+
+  SEQUENCE_CHECKER(sequence_checker_);
+
+  base::WeakPtrFactory<HidConnectionFreeBSD> weak_factory_;
+
+  DISALLOW_COPY_AND_ASSIGN(HidConnectionFreeBSD);
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_CONNECTION_FREEBSD_H_
