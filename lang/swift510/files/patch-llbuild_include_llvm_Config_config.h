--- llbuild/include/llvm/Config/config.h.orig	2024-01-09 06:44:05 UTC
+++ llbuild/include/llvm/Config/config.h
@@ -131,7 +131,7 @@
 /* #undef HAVE_LSEEK64 */
 
 /* Define to 1 if you have the `mallctl' function. */
-/* #undef HAVE_MALLCTL */
+#define HAVE_MALLCTL 1
 
 /* Define to 1 if you have the `mallinfo' function. */
 /* #undef HAVE_MALLINFO */
