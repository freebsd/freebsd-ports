--- src/mixer.c.orig	Wed Jun 26 22:57:26 2002
+++ src/mixer.c	Wed Jun 26 22:57:38 2002
@@ -36,7 +36,7 @@
 #endif
 
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 
 #if defined(__NetBSD__) || defined(__OpenBSD__)
