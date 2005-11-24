--- src/arch/bsd/bsd_dsp.c.orig	Wed Nov  9 13:15:27 2005
+++ src/arch/bsd/bsd_dsp.c	Wed Nov  9 14:09:12 2005
@@ -113,7 +113,6 @@
  */
 void *grab_write_native(void) {
 	const char *dsppath = "/dev/dsp";
-	int divisor = _alSpot(_AL_DEF_BUFSIZ) | (2<<16);
 
 	dsp_fd = open(dsppath, O_WRONLY | O_NONBLOCK);
 
@@ -126,10 +125,6 @@
 		perror("fcntl");
 	}
 
-	if(ioctl(dsp_fd, SNDCTL_DSP_SETFRAGMENT, &divisor) < 0) {
-		perror("ioctl SETFRAGMENT");
-	}
-
 	_alBlitBuffer = native_blitbuffer;
 
 	FD_ZERO(&dsp_fd_set);
@@ -320,10 +315,11 @@
 }
 
 ALboolean set_write_native(UNUSED(void *handle),
-		     UNUSED(unsigned int *bufsiz),
+		     unsigned int *bufsiz,
 		     ALenum *fmt,
 		     unsigned int *speed) {
 	ALuint channels = _al_ALCHANNELS(*fmt);
+	int divisor;
 
 	if(dsp_fd < 0) {
 		return AL_FALSE;
@@ -365,6 +361,23 @@
 
 
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
