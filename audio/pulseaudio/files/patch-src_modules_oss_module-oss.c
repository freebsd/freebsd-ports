--- src/modules/oss/module-oss.c.orig	2014-01-23 13:57:55.000000000 -0500
+++ src/modules/oss/module-oss.c	2014-03-05 15:56:36.924173392 -0500
@@ -1229,10 +1229,12 @@
         use_mmap = false;
     }
 
+#ifndef __FreeBSD__
     if (use_mmap && mode == O_WRONLY) {
         pa_log_info("Device opened for playback only, cannot do memory mapping, falling back to UNIX write() mode.");
         use_mmap = false;
     }
+#endif
 
     if (pa_oss_get_hw_description(dev, hwdesc, sizeof(hwdesc)) >= 0)
         pa_log_info("Hardware name is '%s'.", hwdesc);
@@ -1428,7 +1430,7 @@
     if ((u->mixer_fd = pa_oss_open_mixer_for_device(u->device_name)) >= 0) {
         bool do_close = true;
 
-        if (ioctl(fd, SOUND_MIXER_READ_DEVMASK, &u->mixer_devmask) < 0)
+        if (ioctl(u->mixer_fd, SOUND_MIXER_READ_DEVMASK, &u->mixer_devmask) < 0)
             pa_log_warn("SOUND_MIXER_READ_DEVMASK failed: %s", pa_cstrerror(errno));
         else {
             if (u->sink && (u->mixer_devmask & (SOUND_MASK_VOLUME|SOUND_MASK_PCM))) {
