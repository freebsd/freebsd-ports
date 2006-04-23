--- src/backends/alc_backend_bsd.c.orig	Sat Apr 22 12:25:15 2006
+++ src/backends/alc_backend_bsd.c	Sat Apr 22 12:26:15 2006
@@ -9,7 +9,10 @@
  */
 #include "al_siteconfig.h"
 
+#define __BSD_VISIBLE 1
+
 #include <AL/al.h>
+#include <AL/alext.h>
 #include <assert.h>
 #include <fcntl.h>
 #include <sys/soundcard.h>
@@ -113,7 +114,6 @@
  */
 static void *grab_write_native(void) {
	const char *dsppath = "/dev/dsp";
-	int divisor = _alSpot(_AL_DEF_BUFSIZ) | (2<<16);

	dsp_fd = open(dsppath, O_WRONLY | O_NONBLOCK);

@@ -126,10 +126,6 @@
		perror("fcntl");
	}

-	if(ioctl(dsp_fd, SNDCTL_DSP_SETFRAGMENT, &divisor) < 0) {
-		perror("ioctl SETFRAGMENT");
-	}
-
	FD_ZERO(&dsp_fd_set);
	FD_SET(dsp_fd, &dsp_fd_set);

@@ -318,10 +314,11 @@
 }

 static ALboolean set_write_native(UNUSED(void *handle),
-				  UNUSED(unsigned int *bufsiz),
+				  unsigned int *bufsiz,
				  ALenum *fmt,
				  unsigned int *speed) {
	ALuint channels = _alGetChannelsFromFormat(*fmt);
+	int divisor;

	if(dsp_fd < 0) {
		return AL_FALSE;
@@ -363,6 +360,23 @@


	*fmt = BSD2ALFMT(*fmt, channels);
+
+	if(ioctl(dsp_fd, SNDCTL_DSP_GETBLKSIZE, bufsiz) < 0) {
+#ifdef DEBUG_MAXIMUS
+		fprintf(stderr, "blksize %d\n", *bufsiz);
+		perror("get_devsp blksize ioctl");
+#endif
+		return AL_FALSE;
+	}
+
+	divisor = _alSpot(*bufsiz) | (2<<16);
+	if(ioctl(dsp_fd, SNDCTL_DSP_SETFRAGMENT, &divisor) < 0) {
+#ifdef DEBUG_MAXIMUS
+		fprintf(stderr, "divisor %d\n", divisor);
+		perror("set_devsp fragment ioctl");
+#endif
+		return AL_FALSE;
+	}

	return AL_TRUE;
 }
