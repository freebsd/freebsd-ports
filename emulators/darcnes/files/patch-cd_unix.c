--- cd_unix.c.orig	Sun Aug 20 03:25:53 2000
+++ cd_unix.c
@@ -62,7 +62,6 @@
 
 void cd_play_track(u8 track)
 {
-#ifdef SYSTEM_FREEBSD
     struct ioc_play_track playtrack;
 
     /* FIXME: CD keeps playing after program quits */
@@ -74,12 +73,10 @@
     playtrack.end_index = 1;
 
     ioctl(cd_drive, CDIOCPLAYTRACKS, &playtrack);
-#endif
 }
 
 void cd_play_lba(u32 from, u32 to, int repeat)
 {
-#ifdef SYSTEM_FREEBSD
     struct ioc_play_blocks playblocks;
 
     /* FIXME: ignores the repeat flag */
@@ -94,7 +91,6 @@
     playblocks.len = to - from;
 
     ioctl(cd_drive, CDIOCPLAYBLOCKS, &playblocks);
-#endif
 }
 
 #ifdef SYSTEM_LINUX
