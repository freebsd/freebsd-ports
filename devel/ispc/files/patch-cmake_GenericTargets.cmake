--- cmake/GenericTargets.cmake.orig	2026-06-25 04:07:31 UTC
+++ cmake/GenericTargets.cmake
@@ -84,7 +84,7 @@ function (generate_generic_builtins ispc_name)
         )
     endif()
 
-    if (PPC64_ENABLED AND ISPC_LINUX_TARGET)
+    if (PPC64_ENABLED AND (ISPC_LINUX_TARGET OR ISPC_FREEBSD_TARGET))
         list(APPEND ARCH_LIST
             "ppc64le,64"
         )
