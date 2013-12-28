--- src/libcw/libcw_oss.c.orig	2013-12-26 11:47:03.000000000 -0500
+++ src/libcw/libcw_oss.c	2013-12-27 18:56:52.000000000 -0500
@@ -291,14 +291,14 @@
 			      "cw_oss: ioctl(SNDCTL_DSP_SYNC): \"%s\"", strerror(errno));
 		return CW_FAILURE;
         }
-
+#if 0
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
