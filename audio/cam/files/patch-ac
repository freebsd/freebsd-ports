diff -ru ../cam-1.02-virgin/sounds.c ./sounds.c
--- ../cam-1.02-virgin/sounds.c	Mon Oct 21 13:33:55 1996
+++ ./sounds.c	Sun Nov 10 12:20:22 1996
@@ -36,7 +36,7 @@
 
 
 int mixer_fd, recmask, devmask, stereodevs, recsrc;
-char *devname[DEV_COUNT] = SOUND_DEVICE_LABELS;
+char *cam_devname[DEV_COUNT] = SOUND_DEVICE_LABELS;
 char *mixer_dev = "/dev/mixer";
 struct devices
 {
@@ -287,7 +287,7 @@
           else
              dev_vol[dev_count].vol_right = dev_vol[dev_count].vol_left;
 
-          draw_slider( Y, X, devname[dev_nr]);
+          draw_slider( Y, X, cam_devname[dev_nr]);
           draw_handle( Y+1, X+14+dev_vol[dev_count].vol_left, FALSE, 4);
           if (STEREO(dev_nr))
              draw_handle( Y+2, X+14+dev_vol[dev_count].vol_right, FALSE, 4);          
