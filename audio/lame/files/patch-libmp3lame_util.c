--- libmp3lame/util.c.orig	2021-06-11 15:08:59 UTC
+++ libmp3lame/util.c
@@ -843,9 +843,8 @@ disable_FPE(void)
      */
 
 
-
-
-#if defined(__FreeBSD__) && !defined(__alpha__)
+/* https://reviews.llvm.org/D89557 */
+#if defined(__FreeBSD__) && defined(FP_X_INV) && defined(FP_X_DZ)
     {
         /* seet floating point mask to the Linux default */
         fp_except_t mask;
