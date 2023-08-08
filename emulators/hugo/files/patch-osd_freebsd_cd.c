--- osd_freebsd_cd.c.orig	2003-10-12 21:45:03 UTC
+++ osd_freebsd_cd.c
@@ -38,7 +38,7 @@ void osd_cd_close()
 }
 
 
-int osd_cd_read(UChar *p, UInt32 sector)
+void osd_cd_read(UChar *p, UInt32 sector)
 {
 /*
   int retries = 0;
@@ -236,15 +236,3 @@ void osd_cd_play_audio_range(UChar min_from, UChar sec
     perror("play_audio_range");
 */
 }
-
-void osd_cd_subchannel_info(unsigned short offset)
-{ }
- 
-void osd_cd_status(int *status)
-{}
-
-void osd_cd_resume(void)
-{}
-
-void osd_cd_pause(void)
-{}
