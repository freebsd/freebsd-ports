--- mixctl.h.orig	2001-03-02 10:32:05 UTC
+++ mixctl.h
@@ -19,7 +19,7 @@
 #include <soundcard.h>
 #endif
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 #ifdef __linux__
 #include <linux/soundcard.h>
