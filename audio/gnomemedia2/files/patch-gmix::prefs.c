--- gmix/prefs.c.orig	Tue May  7 00:52:42 2002
+++ gmix/prefs.c	Tue May  7 00:52:54 2002
@@ -38,7 +38,7 @@
 #ifdef HAVE_LINUX_SOUNDCARD_H 
 #include <linux/soundcard.h>
 #else 
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 #endif
 
