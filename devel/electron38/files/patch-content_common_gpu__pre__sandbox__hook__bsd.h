--- content/common/gpu_pre_sandbox_hook_bsd.h.orig	2024-02-27 21:36:23 UTC
+++ content/common/gpu_pre_sandbox_hook_bsd.h
@@ -0,0 +1,20 @@
+// Copyright 2017 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef CONTENT_COMMON_GPU_PRE_SANDBOX_HOOK_BSD_H_
+#define CONTENT_COMMON_GPU_PRE_SANDBOX_HOOK_BSD_H_
+
+#include "base/component_export.h"
+#include "sandbox/policy/sandbox.h"
+
+namespace content {
+
+// A pre-sandbox hook to use on Linux-based systems in sandboxed processes that
+// require general GPU usage.
+COMPONENT_EXPORT(GPU_PRE_SANDBOX_HOOK)
+bool GpuPreSandboxHook(sandbox::policy::SandboxLinux::Options options);
+
+}  // namespace content
+
+#endif  // CONTENT_COMMON_GPU_PRE_SANDBOX_HOOK_BSD_H_
