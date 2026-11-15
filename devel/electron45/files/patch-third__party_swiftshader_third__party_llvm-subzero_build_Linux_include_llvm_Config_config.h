--- third_party/swiftshader/third_party/llvm-subzero/build/Linux/include/llvm/Config/config.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/swiftshader/third_party/llvm-subzero/build/Linux/include/llvm/Config/config.h
@@ -5,8 +5,6 @@
 #include "llvm/Config/llvm-config.h"
 
 /* For detecting __GLIBC__ usage */
-#include <features.h>
-
 /* Bug report URL. */
 #define BUG_REPORT_URL "http://llvm.org/bugs/"
 
@@ -27,7 +25,7 @@
 
 /* Define to 1 if you have the declaration of `arc4random', and to 0 if you
    don't. */
-#define HAVE_DECL_ARC4RANDOM 0
+#define HAVE_DECL_ARC4RANDOM 1
 
 /* Define to 1 if you have the declaration of `FE_ALL_EXCEPT', and to 0 if you
    don't. */
@@ -124,7 +122,7 @@
 #define HAVE_LINK_H 1
 
 /* Define to 1 if you have the `lseek64' function. */
-#define HAVE_LSEEK64 1
+/* #define HAVE_LSEEK64 */
 
 /* Define to 1 if you have the <mach/mach.h> header file. */
 /* #undef HAVE_MACH_MACH_H */
@@ -133,7 +131,7 @@
 /* #undef HAVE_MALLCTL */
 
 /* Define to 1 if you have the `mallinfo' function. */
-#define HAVE_MALLINFO 1
+/* #define HAVE_MALLINFO */
 
 /* Some projects using SwiftShader bypass cmake (eg Chromium via gn) */
 /* so we need to check glibc version for the new API to be safe */
@@ -163,7 +161,7 @@
 /* #undef HAVE_NDIR_H */
 
 /* Define to 1 if you have the `posix_fallocate' function. */
-#define HAVE_POSIX_FALLOCATE 1
+/* #define HAVE_POSIX_FALLOCATE */
 
 /* Define to 1 if you have the `posix_spawn' function. */
 #define HAVE_POSIX_SPAWN 1
