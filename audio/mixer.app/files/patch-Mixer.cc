--- Mixer.cc.orig	Sat Sep  7 16:55:38 2002
+++ Mixer.cc	Sat Sep  7 16:55:56 2002
@@ -33,8 +33,6 @@
 
 #if defined(__Linux__)
 #include <linux/soundcard.h>
-#elif defined(__FreeBSD__)
-#include <machine/soundcard.h>
 #else
 #include <sys/soundcard.h>
 #endif
