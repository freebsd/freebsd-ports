--- include/wm_config.h.orig	1999-05-05 16:34:22 UTC
+++ include/wm_config.h
@@ -133,7 +133,7 @@
  ***  ******  **  **  ******  ******  **  ******  **  *  **********
  ***  ******  **  **      **      **     ****    ***    ***********
  ******************************************************************/
-#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 
 #define DEFAULT_CD_DEVICE	"/dev/rmatcd0c"
 
