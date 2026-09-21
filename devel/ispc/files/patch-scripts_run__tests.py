--- scripts/run_tests.py.orig	2026-09-19 15:38:14 UTC
+++ scripts/run_tests.py
@@ -1365,7 +1365,7 @@ elif platform.machine() == "arm64":
 elif platform.machine() == "arm64":
     default_target = "neon-i32x4"
     default_arch = "aarch64"
-elif platform.machine() == "ppc64le":
+elif platform.machine() == "ppc64le" or platform.processor() == "powerpc64le":
     default_target = "generic-i32x4"
     default_arch = "ppc64le"
 elif "86" in platform.machine() or platform.machine() == "AMD64":
