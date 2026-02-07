--- lib/igt_audio.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_audio.c
@@ -26,6 +26,10 @@
 
 #include "config.h"
 
+#ifdef __FreeBSD__
+#include <limits.h>
+#endif
+
 #include <errno.h>
 #include <fcntl.h>
 #include <gsl/gsl_fft_real.h>
