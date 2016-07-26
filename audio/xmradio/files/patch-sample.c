--- sample.c.orig	2001-12-04 20:52:55 UTC
+++ sample.c
@@ -43,7 +43,7 @@
 #ifdef __NetBSD__
 #include <soundcard.h>
 #else
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 #include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h>
