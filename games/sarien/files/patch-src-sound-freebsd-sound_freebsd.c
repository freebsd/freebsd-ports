--- src/sound/freebsd/sound_freebsd.c.orig	Fri Jun 22 16:45:04 2001
+++ src/sound/freebsd/sound_freebsd.c	Tue May 25 19:36:22 2004
@@ -16,7 +16,7 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "sarien.h"
 #include "sound.h"
