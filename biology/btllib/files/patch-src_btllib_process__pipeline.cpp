-- /dev/shm can only be used on Limux.
-- upstreamed: https://github.com/BirolLab/btllib/pull/152

--- src/btllib/process_pipeline.cpp.orig	2026-10-16 20:52:17 UTC
+++ src/btllib/process_pipeline.cpp
@@ -698,7 +698,12 @@ set_pipepath_prefix()
 {
   struct stat info
   {};
-  if ((stat("/dev/shm", &info) == 0) && ((info.st_mode & S_IFMT) == S_IFDIR)) {
+#if defined(__linux__)
+  const bool is_linux = true;
+#else
+  const bool is_linux = false;
+#endif
+  if (is_linux && (stat("/dev/shm", &info) == 0) && ((info.st_mode & S_IFMT) == S_IFDIR)) {
     pipepath_prefix = "/dev/shm/";
   } else {
     const auto* const tmpdir =
