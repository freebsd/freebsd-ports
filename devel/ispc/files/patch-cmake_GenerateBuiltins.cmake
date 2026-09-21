--- cmake/GenerateBuiltins.cmake.orig	2026-06-25 04:07:31 UTC
+++ cmake/GenerateBuiltins.cmake
@@ -479,6 +479,10 @@ function (generate_common_builtins)
         builtin_to_cpp(64 freebsd x86)
     endif()
 
+    if (ISPC_FREEBSD_TARGET AND PPC64_ENABLED)
+        builtin_to_cpp(64 freebsd ppc)
+    endif()
+
     if (ISPC_WINDOWS_TARGET AND ARM_ENABLED)
         builtin_to_cpp(64 windows arm)
     endif()
