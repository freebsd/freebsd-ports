--- wav2pat.c.orig	1996-05-20 13:09:47 UTC
+++ wav2pat.c
@@ -28,7 +28,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 
-#ifdef SOLARIS
+#if defined(SOLARIS) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
