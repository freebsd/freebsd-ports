--- linux_x/sndserv/linux.c.orig	Sat Jan 18 18:29:07 2003
+++ linux_x/sndserv/linux.c	Sat Jan 18 18:29:12 2003
@@ -45,7 +45,7 @@
 
 #ifdef LINUX
 #ifdef FREEBSD
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #else
 #include <linux/soundcard.h>
 #endif
