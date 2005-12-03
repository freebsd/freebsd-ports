--- src/sound.c.orig	Wed Sep 14 22:27:31 2005
+++ src/sound.c	Sat Dec  3 18:54:20 2005
@@ -1233,7 +1233,7 @@
 
 /* don't use uss for FreeBSD or BSDI */
 
-#if !defined(__FreeBSD__) && !defined(__bsdi__)
+#if !defined(__bsdi__)
     sound_init_uss_device();
 #endif
 #endif
