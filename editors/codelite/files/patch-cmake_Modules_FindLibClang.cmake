--- cmake/Modules/FindLibClang.cmake.orig	2015-08-16 12:16:16.000000000 +0300
+++ cmake/Modules/FindLibClang.cmake	2015-08-16 12:18:08.000000000 +0300
@@ -12,6 +12,11 @@
                      # For fedora
                      /usr/lib/llvm
                      /usr/lib64/llvm
+                     # For FreeBSD
+                     /usr/local/llvm36/lib
+                     /usr/local/llvm35/lib
+                     /usr/local/llvm34/lib
+                     /usr/local/llvm33/lib
                      ${CMAKE_INSTALL_LIBDIR})
 
         find_path(LIBCLANG_INCLUDE_T NAMES clang-c/Index.h
@@ -28,6 +33,11 @@
                   /usr/local/include
                   # For fedora
                   /usr/include
+                  # For FreeBSD
+                  /usr/local/llvm36/include
+                  /usr/local/llvm35/include
+                  /usr/local/llvm34/include
+                  /usr/local/llvm33/include
                   )
 
         if ( LIBCLANG_T STREQUAL "LIBCLANG_T-NOTFOUND" OR LIBCLANG_INCLUDE_T STREQUAL "LIBCLANG_INCLUDE_T-NOTFOUND" )
