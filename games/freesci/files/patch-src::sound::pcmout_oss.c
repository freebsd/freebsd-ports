--- src/sound/pcmout_oss.c.orig	Thu Feb 20 20:52:48 2003
+++ src/sound/pcmout_oss.c	Thu Feb 20 21:02:06 2003
@@ -75,6 +75,15 @@
 		return -1;
 	}
 
+/* Some OSS don't define the native endian */
+#ifndef AFMT_S16_NE
+	#if defined __i386__ || defined __alpha__
+		#define AFMT_S16_NE AFMT_S16_LE
+	#elif defined __mips__
+		#define AFMT_S16_NE AFMT_S16_BE
+	#endif
+	/* FIXME are these correct? */
+#endif
 	i = AFMT_S16_NE;  /* Use NATIVE endian format... */
 	if (ioctl (oss_fd, SNDCTL_DSP_SETFMT, &i)) {
 		fprintf(stderr, "[PCM-OSS] Failed to set device output format\n");
