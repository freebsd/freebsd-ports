--- src/modules/oss/module-oss.c.orig	2009-04-13 17:11:32.000000000 -0400
+++ src/modules/oss/module-oss.c	2009-07-19 14:24:25.000000000 -0400
@@ -1214,10 +1214,12 @@ int pa__init(pa_module*m) {
         use_mmap = FALSE;
     }
 
+#ifndef __FreeBSD__
     if (use_mmap && mode == O_WRONLY) {
         pa_log_info("Device opened for playback only, cannot do memory mapping, falling back to UNIX write() mode.");
         use_mmap = FALSE;
     }
+#endif
 
     if (pa_oss_get_hw_description(dev, hwdesc, sizeof(hwdesc)) >= 0)
         pa_log_info("Hardware name is '%s'.", hwdesc);
@@ -1399,7 +1401,7 @@ int pa__init(pa_module*m) {
     if ((u->mixer_fd = pa_oss_open_mixer_for_device(u->device_name)) >= 0) {
         pa_bool_t do_close = TRUE;
 
-        if (ioctl(fd, SOUND_MIXER_READ_DEVMASK, &u->mixer_devmask) < 0)
+        if (ioctl(u->mixer_fd, SOUND_MIXER_READ_DEVMASK, &u->mixer_devmask) < 0)
             pa_log_warn("SOUND_MIXER_READ_DEVMASK failed: %s", pa_cstrerror(errno));
 
         else {
