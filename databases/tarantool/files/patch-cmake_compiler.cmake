--- cmake/compiler.cmake.orig	2015-08-22 18:47:17 UTC
+++ cmake/compiler.cmake
@@ -129,6 +129,10 @@ macro(enable_tnt_compile_flags)
     if (CMAKE_COMPILER_IS_GNUCC)
         # A workaround for Redhat Developer Toolset 2.x on RHEL/CentOS 5.x
         add_compile_flags("C" "-fno-gnu89-inline")
+        if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
+            add_compile_flags("C;CXX"
+	        "-march=i686")
+        endif()
     endif()
 
     add_definitions("-D__STDC_FORMAT_MACROS=1")
