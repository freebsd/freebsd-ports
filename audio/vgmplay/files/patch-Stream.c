--- Stream.c.orig	2019-01-08 12:56:30 UTC
+++ Stream.c
@@ -16,6 +16,8 @@
 #include <fcntl.h>
 #ifdef __NetBSD__
 #include <sys/audioio.h>
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
 #elif defined(__APPLE__) || defined(__OpenBSD__)
 // nothing
 #else
