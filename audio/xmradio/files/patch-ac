--- analyzer.c.orig	Sun Sep  8 03:00:48 2002
+++ analyzer.c	Sun Sep  8 03:01:47 2002
@@ -37,7 +37,7 @@
 #include <soundcard.h>
 #include <sys/ioctl.h>
 #else
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 #include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h>
