--- output/oss/oss.c.orig	Wed Jul  2 17:10:24 2003
+++ output/oss/oss.c	Wed Jul  2 17:13:47 2003
@@ -84,7 +84,15 @@
 	
 	val = (count << 16) + hops;
 	ioctl(oss_fd,SNDCTL_DSP_SETFRAGMENT,&val);
+#ifndef AFMT_S16_NE
+#if BYTE_ORDER == LITTLE_ENDIAN
+	val = AFMT_S16_LE;
+#else
+	val = AFMT_S16_BE;
+#endif
+#else
 	val = AFMT_S16_NE;
+#endif
 	ioctl(oss_fd,SNDCTL_DSP_SETFMT,&val);
 	val = *channels - 1;
 	ioctl(oss_fd,SNDCTL_DSP_STEREO,&val);
