--- tnsuplu.h.orig	Wed Jun 18 12:39:20 2003
+++ tnsuplu.h	Wed Jun 18 12:45:46 2003
@@ -2,6 +2,12 @@
 #define SUPERLU_USE 0
 #define SUPERLU_MT_USE 0
 #define SUPERLU_DIST_USE 0
+#if SUPERLU_USE /* enums were changed for SuperLU v2 */
+#define _D SLU_D
+#define DN SLU_DN
+#define GE SLU_GE
+#define NC SLU_NC
+#endif
 /* don't change the next lines */
 #if SUPERLU_USE+SUPERLU_MT_USE+SUPERLU_DIST_USE > 1
  ERROR___  just pick one 
