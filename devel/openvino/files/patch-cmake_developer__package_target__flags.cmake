--- cmake/developer_package/target_flags.cmake.orig	2026-01-08 09:24:41 UTC
+++ cmake/developer_package/target_flags.cmake
@@ -166,7 +166,7 @@ endfunction()
     endif()
 endfunction()
 
-if(LINUX)
+if(UNIX)
   ov_detect_libc_type()
 endif()
 
@@ -207,7 +207,7 @@ function(ov_libc_version)
 
 function(ov_libc_version)
     # cmake needs to look at glibc version only when we build for Linux on Linux
-    if(LINUX)
+    if(UNIX)
         if(OPENVINO_GNU_LIBC)
             ov_get_compiler_definition("__GLIBC__" _ov_glibc_major)
             ov_get_compiler_definition("__GLIBC_MINOR__" _ov_glibc_minor)
@@ -224,7 +224,7 @@ endfunction()
     endif()
 endfunction()
 
-ov_libc_version()
+#ov_libc_version()
 
 #
 # Detects default value for _GLIBCXX_USE_CXX11_ABI for current compiler
