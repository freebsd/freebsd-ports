--- src/modules/module-oss.c.orig	2009-07-10 02:51:21.000000000 -0400
+++ src/modules/module-oss.c	2009-07-10 02:52:05.000000000 -0400
@@ -1204,10 +1204,12 @@ int pa__init(pa_module*m) {
         use_mmap = 0;
     }
 
+#ifndef __FreeBSD__
     if (use_mmap && mode == O_WRONLY) {
         pa_log_info("Device opened for playback only, cannot do memory mapping, falling back to UNIX write() mode.");
         use_mmap = 0;
     }
+#endif
 
     if (pa_oss_get_hw_description(dev, hwdesc, sizeof(hwdesc)) >= 0)
         pa_log_info("Hardware name is '%s'.", hwdesc);
@@ -1385,7 +1387,7 @@ int pa__init(pa_module*m) {
         pa_bool_t do_close = TRUE;
         u->mixer_devmask = 0;
 
-        if (ioctl(fd, SOUND_MIXER_READ_DEVMASK, &u->mixer_devmask) < 0)
+        if (ioctl(u->mixer_fd, SOUND_MIXER_READ_DEVMASK, &u->mixer_devmask) < 0)
             pa_log_warn("SOUND_MIXER_READ_DEVMASK failed: %s", pa_cstrerror(errno));
 
         else {
