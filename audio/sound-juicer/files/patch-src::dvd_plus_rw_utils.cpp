--- src/dvd_plus_rw_utils.cpp.orig	Wed Jan 21 12:47:50 2004
+++ src/dvd_plus_rw_utils.cpp	Wed Jan 21 12:48:04 2004
@@ -113,7 +113,7 @@
 }
 
 extern "C"
-int get_mmc_profile (void *fd)
+int get_mmc_profile (int fd)
 { Scsi_Command cmd(fd);
   unsigned char buf[8];
   int profile=-1,once=1;
