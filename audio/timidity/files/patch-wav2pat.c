--- ./wav2pat.c.orig	1996-05-20 08:09:47.000000000 -0500
+++ ./wav2pat.c	2013-04-21 10:18:23.000000000 -0500
@@ -28,7 +28,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 
-#ifdef SOLARIS
+#if defined(SOLARIS) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
