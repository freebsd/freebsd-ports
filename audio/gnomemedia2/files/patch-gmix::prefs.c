--- gmix/prefs.c.orig	Fri Apr 12 11:53:51 2002
+++ gmix/prefs.c	Fri Apr 12 11:53:57 2002
@@ -38,7 +38,7 @@
 #ifdef HAVE_LINUX_SOUNDCARD_H 
 #include <linux/soundcard.h>
 #else 
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 #endif
 
