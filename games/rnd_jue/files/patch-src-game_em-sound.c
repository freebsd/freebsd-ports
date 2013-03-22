--- src/game_em/sound.c.orig	2007-04-25 23:37:09.000000000 +0200
+++ src/game_em/sound.c	2012-12-12 02:10:57.000000000 +0100
@@ -10,15 +10,8 @@
 
 #if defined(PLATFORM_LINUX) || defined(PLATFORM_BSD)
 
-#ifdef PLATFORM_LINUX
 #include <sys/ioctl.h>
 #include <sys/soundcard.h>
-#endif
-
-#ifdef PLATFORM_BSD
-#include <ioctl.h>
-#include <soundcard.h>
-#endif
 
 static char audioname[] = "/dev/audio";
 
