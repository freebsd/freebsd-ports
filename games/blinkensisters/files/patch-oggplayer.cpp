--- oggplayer.cpp.orig	2008-12-06 23:51:54.000000000 +0300
+++ oggplayer.cpp	2013-12-20 21:39:40.586265026 +0400
@@ -68,7 +68,7 @@
    hard/kernel buffer is going to be most of or > a second, that's
    just a little bit important */
 #if defined(__FreeBSD__)
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #define AUDIO_DEVICE "/dev/audio"
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 #include <soundcard.h>
