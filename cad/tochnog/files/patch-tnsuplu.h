--- tnsuplu.h.orig	Sun Aug 19 12:31:52 2001
+++ tnsuplu.h	Fri Feb  3 15:55:13 2006
@@ -2,6 +2,12 @@
 #define SUPERLU_USE 0
 #define SUPERLU_MT_USE 0
 #define SUPERLU_DIST_USE 0
+/* enums were changed for SuperLU v2 */
+#define _D SLU_D
+#define DN SLU_DN
+#define GE SLU_GE
+#define NC SLU_NC
+
 /* don't change the next lines */
 #if SUPERLU_USE+SUPERLU_MT_USE+SUPERLU_DIST_USE > 1
  ERROR___  just pick one 
