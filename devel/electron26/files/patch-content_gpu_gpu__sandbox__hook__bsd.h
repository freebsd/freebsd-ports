--- content/gpu/gpu_sandbox_hook_bsd.h.orig	2023-06-07 04:52:28 UTC
+++ content/gpu/gpu_sandbox_hook_bsd.h
@@ -0,0 +1,16 @@
+// Copyright 2023 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef CONTENT_GPU_GPU_SANDBOX_HOOK_BSD_H_
+#define CONTENT_GPU_GPU_SANDBOX_HOOK_BSD_H_
+
+#include "sandbox/policy/sandbox.h"
+
+namespace content {
+
+bool GpuProcessPreSandboxHook(sandbox::policy::SandboxLinux::Options options);
+
+}  // namespace content
+
+#endif  // CONTENT_GPU_GPU_SANDBOX_HOOK_BSD_H_
