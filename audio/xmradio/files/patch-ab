--- sample.c.orig	Sun Sep  8 03:00:57 2002
+++ sample.c	Sun Sep  8 03:01:20 2002
@@ -43,7 +43,7 @@
 #ifdef __NetBSD__
 #include <soundcard.h>
 #else
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 #include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h>
