--- src/modules/oss/module-oss.c.orig	2015-08-06 11:39:12.000000000 +0200
+++ src/modules/oss/module-oss.c	2015-09-03 13:13:37.953255000 +0200
@@ -1227,10 +1227,14 @@
         use_mmap = false;
     }
 
+#ifndef __FreeBSD__
+/* Disable mmap. The OSS on FreeBSD doesn't support read & write on 
+   the same socket */
     if (use_mmap && mode == O_WRONLY) {
         pa_log_info("Device opened for playback only, cannot do memory mapping, falling back to UNIX write() mode.");
         use_mmap = false;
     }
+#endif
 
     if (pa_oss_get_hw_description(dev, hwdesc, sizeof(hwdesc)) >= 0)
         pa_log_info("Hardware name is '%s'.", hwdesc);
