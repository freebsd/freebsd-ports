--- mixctl.h.orig	Tue Mar  6 07:39:43 2001
+++ mixctl.h	Thu Apr 25 21:19:40 2002
@@ -19,7 +19,7 @@
 #include <soundcard.h>
 #endif
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 #ifdef __linux__
 #include <linux/soundcard.h>
