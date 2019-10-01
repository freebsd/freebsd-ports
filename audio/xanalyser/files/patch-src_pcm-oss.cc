--- src/pcm-oss.cc.orig	2006-07-03 20:05:03 UTC
+++ src/pcm-oss.cc
@@ -100,7 +100,8 @@ PCMOSS::PCMOSS (const char* name, pcm_type_t type, pcm
     }
 
     int tmp_buffer_size = want_buffer_size;
-    if (ioctl (fd, SNDCTL_DSP_GETBLKSIZE, &tmp_buffer_size) == -1) {
+    if (ioctl (fd, SNDCTL_DSP_SETBLKSIZE, &tmp_buffer_size) == -1 ||
+	ioctl (fd, SNDCTL_DSP_GETBLKSIZE, &tmp_buffer_size) == -1) {
 	cerr << "error " << strerror (errno) << '\n';
 	return;
     }
