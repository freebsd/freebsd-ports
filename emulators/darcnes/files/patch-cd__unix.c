--- cd_unix.c.orig	2000-10-30 22:18:23 UTC
+++ cd_unix.c
@@ -62,7 +62,6 @@ void cd_read_next_sector(u8 *buf)
 
 void cd_play_track(u8 track)
 {
-#ifdef SYSTEM_FREEBSD
     struct ioc_play_track playtrack;
 
     /* FIXME: CD keeps playing after program quits */
@@ -74,12 +73,10 @@ void cd_play_track(u8 track)
     playtrack.end_index = 1;
 
     ioctl(cd_drive, CDIOCPLAYTRACKS, &playtrack);
-#endif
 }
 
 void cd_play_lba(u32 from, u32 to, int repeat)
 {
-#ifdef SYSTEM_FREEBSD
     struct ioc_play_blocks playblocks;
 
     /* FIXME: ignores the repeat flag */
@@ -94,7 +91,6 @@ void cd_play_lba(u32 from, u32 to, int repeat)
     playblocks.len = to - from;
 
     ioctl(cd_drive, CDIOCPLAYBLOCKS, &playblocks);
-#endif
 }
 
 #ifdef SYSTEM_LINUX
