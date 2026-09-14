--- cmake/build_configurations/compiler_options.cmake.orig	2026-06-30 16:11:51 UTC
+++ cmake/build_configurations/compiler_options.cmake
@@ -68,7 +68,7 @@ IF(UNIX)  
   # Faster TLS model
   # libprotobuf-lite.so.24.4: cannot allocate memory in static TLS block
   IF(MY_COMPILER_IS_GNU_OR_CLANG
-      AND NOT LINUX_ARM
+      AND NOT LINUX_ARM AND NOT FREEBSD
       AND NOT SOLARIS AND NOT LINUX_RHEL6 AND NOT LINUX_ALPINE)
     STRING_APPEND(COMMON_C_FLAGS     " -ftls-model=initial-exec")
     STRING_APPEND(COMMON_CXX_FLAGS   " -ftls-model=initial-exec")
