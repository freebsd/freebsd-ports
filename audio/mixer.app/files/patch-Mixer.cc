--- Mixer.cc.orig	2002-09-15 16:42:33 UTC
+++ Mixer.cc
@@ -33,8 +33,6 @@
 
 #if defined(__Linux__)
 #include <linux/soundcard.h>
-#elif defined(__FreeBSD__)
-#include <machine/soundcard.h>
 #elif defined(__OpenBSD__)
 #include <soundcard.h>
 #else
