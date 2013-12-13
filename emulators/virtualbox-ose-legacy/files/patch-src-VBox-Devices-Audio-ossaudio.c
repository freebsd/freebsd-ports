Fix recording with OSS Audio backend to record at a proper volume

Obtained from:	https://www.virtualbox.org/ticket/10695
--- src/VBox/Devices/Audio/ossaudio.c.orig	2012-12-19 19:26:32.000000000 +0100
+++ src/VBox/Devices/Audio/ossaudio.c	2012-12-20 12:23:18.476851732 +0100
@@ -795,13 +795,8 @@
                            hw->info.align + 1);
                 }
                 read_samples += nread >> hwshift;
-#ifndef VBOX
                 hw->conv (hw->conv_buf + bufs[i].add, p, nread >> hwshift,
                           &nominal_volume);
-#else
-                hw->conv (hw->conv_buf + bufs[i].add, p, nread >> hwshift,
-                          &pcm_in_volume);
-#endif
             }
 
             if (bufs[i].len - nread) {
