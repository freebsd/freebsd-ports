$FreeBSD$

--- speech_tools/audio/voxware.cc.orig	Tue Sep 28 16:38:22 1999
+++ speech_tools/audio/voxware.cc	Wed Oct 29 08:06:38 2003
@@ -61,7 +61,7 @@
 #include "EST_error.h"
 
 #ifdef SUPPORT_FREEBSD16
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <fcntl.h>
 int freebsd16_supported = TRUE;
 int linux16_supported = FALSE;
