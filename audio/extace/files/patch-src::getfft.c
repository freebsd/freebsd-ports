
$FreeBSD$

--- src/getfft.c	2002/08/30 12:59:05	1.1
+++ src/getfft.c	2002/08/30 12:59:26
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
