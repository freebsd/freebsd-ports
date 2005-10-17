--- speech_tools/audio/voxware.cc.orig	Fri Apr 30 16:56:49 2004
+++ speech_tools/audio/voxware.cc	Sun Oct 16 12:43:12 2005
@@ -61,11 +61,12 @@
 #include "EST_error.h"
 
 #ifdef SUPPORT_FREEBSD16
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <fcntl.h>
 int freebsd16_supported = TRUE;
 int linux16_supported = FALSE;
 static char *aud_sys_name = "FreeBSD";
+static int stereo_only = 0;
 #endif
 
 #ifdef SUPPORT_LINUX16
