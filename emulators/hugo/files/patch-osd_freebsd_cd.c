--- osd_freebsd_cd.c.orig	Fri May 19 01:33:50 2006
+++ osd_freebsd_cd.c	Fri May 19 01:36:44 2006
@@ -38,7 +38,7 @@
 }
 
 
-int osd_cd_read(UChar *p, UInt32 sector)
+void osd_cd_read(UChar *p, UInt32 sector)
 {
 /*
   int retries = 0;
@@ -236,15 +236,3 @@
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
