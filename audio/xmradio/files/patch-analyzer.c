--- analyzer.c.orig	2001-11-13 20:42:08 UTC
+++ analyzer.c
@@ -37,7 +37,7 @@
 #include <soundcard.h>
 #include <sys/ioctl.h>
 #else
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 #include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h>
