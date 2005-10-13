--- src/game_em/sound.c.orig	Sun Apr 24 04:02:41 2005
+++ src/game_em/sound.c	Sat Oct  8 20:13:38 2005
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
 
 #include "global.h"
 #include "sample.h"
