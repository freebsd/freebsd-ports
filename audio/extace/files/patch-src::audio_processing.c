--- src/audio_processing.c.orig	Thu Jun  5 17:20:26 2003
+++ src/audio_processing.c	Thu Jun  5 17:20:45 2003
@@ -20,7 +20,9 @@
 #include <protos.h>
 #include <math.h>
 #include <gtk/gtk.h>
+#ifndef __FreeBSD__
 #include <asm/errno.h>
+#endif
 #include "convolve.h"
 #ifdef HAVE_LIBRFFTW
 #include <rfftw.h>
