--- src/libcw/libcw_oss.c.orig	2013-01-03 17:09:29.000000000 -0500
+++ src/libcw/libcw_oss.c	2013-12-30 14:20:18.000000000 -0500
@@ -48,6 +48,9 @@
 #include <stdbool.h>
 #include <math.h>
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+# include <sys/param.h>
+#endif
 
 #include "libcw_internal.h"
 #include "libcw_oss.h"
@@ -291,14 +294,14 @@
 			      "cw_oss: ioctl(SNDCTL_DSP_SYNC): \"%s\"", strerror(errno));
 		return CW_FAILURE;
         }
-
+#ifndef __FreeBSD__ 
 	parameter = 0; /* ignored */
 	if (ioctl(*fd, SNDCTL_DSP_POST, &parameter) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_DSP_POST): \"%s\"", strerror(errno));
 		return CW_FAILURE;
         }
-
+#endif
 	/* Set the audio format to 8-bit unsigned. */
 	parameter = CW_OSS_SAMPLE_FORMAT;
 	if (ioctl(*fd, SNDCTL_DSP_SETFMT, &parameter) == -1) {
