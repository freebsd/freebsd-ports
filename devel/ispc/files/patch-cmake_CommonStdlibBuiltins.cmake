--- cmake/CommonStdlibBuiltins.cmake.orig	2026-06-25 04:07:31 UTC
+++ cmake/CommonStdlibBuiltins.cmake
@@ -209,7 +209,7 @@ function (generate_stdlib_or_target_builtins func ispc
     endif()
 
     # PPC64 targets (Linux only, 64-bit only)
-    if (PPC64_ENABLED AND ISPC_LINUX_TARGET)
+    if (PPC64_ENABLED AND (ISPC_LINUX_TARGET OR ISPC_FREEBSD_TARGET))
         if (${func} STREQUAL "stdlib_to_cpp")
             foreach (os ${os_list})
                 if (${os} STREQUAL "windows")
