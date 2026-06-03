--- libdd-common/src/unix_utils/fork.rs.orig	2025-08-22 12:57:44.659695000 +0000
+++ libdd-common/src/unix_utils/fork.rs	2025-08-22 12:57:54.570083000 +0000
@@ -1,7 +1,7 @@
 // Copyright 2025-Present Datadog, Inc. https://www.datadoghq.com/
 // SPDX-License-Identifier: Apache-2.0
 
-#[cfg(target_os = "macos")]
+#[cfg(any(target_os = "freebsd", target_os = "macos"))]
 pub fn alt_fork() -> i32 {
     // There is a lower-level `__fork()` function in macOS, and we can call it from Rust, but the
     // runtime is much stricter about which operations (e.g., no malloc) are allowed in the child.
