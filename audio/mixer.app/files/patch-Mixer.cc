--- Mixer.cc.orig	Sun Sep 15 18:42:33 2002
+++ Mixer.cc	Tue Apr 29 01:43:01 2003
@@ -33,8 +33,6 @@
 
 #if defined(__Linux__)
 #include <linux/soundcard.h>
-#elif defined(__FreeBSD__)
-#include <machine/soundcard.h>
 #elif defined(__OpenBSD__)
 #include <soundcard.h>
 #else
