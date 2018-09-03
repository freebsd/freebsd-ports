--- src/pcm-oss.cc	2014-09-06 09:44:07.000000000 +0200
+++ src/pcm-oss.cc	2014-09-06 09:45:02.000000000 +0200
@@ -100,7 +100,8 @@
     }
 
     int tmp_buffer_size = want_buffer_size;
-    if (ioctl (fd, SNDCTL_DSP_GETBLKSIZE, &tmp_buffer_size) == -1) {
+    if (ioctl (fd, SNDCTL_DSP_SETBLKSIZE, &tmp_buffer_size) == -1 ||
+	ioctl (fd, SNDCTL_DSP_GETBLKSIZE, &tmp_buffer_size) == -1) {
 	cerr << "error " << strerror (errno) << '\n';
 	return;
     }
