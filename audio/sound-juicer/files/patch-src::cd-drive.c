--- src/cd-drive.c.orig	Sat Feb  7 18:02:54 2004
+++ src/cd-drive.c	Sat Feb  7 18:03:46 2004
@@ -66,7 +66,7 @@
 
 /* For dvd_plus_rw_utils.cpp */
 int get_dvd_r_rw_profile (const char *name);
-int get_mmc_profile (void *fd);
+int get_mmc_profile (int fd);
 
 static void
 add_dvd_plus (CDDrive *cdrom)
@@ -103,7 +103,7 @@
 		return CD_MEDIA_TYPE_ERROR;
 	}
 
-	mmc_profile = get_mmc_profile ((void *)&fd);
+	mmc_profile = get_mmc_profile (fd);
 	close (fd);
 
 	switch (mmc_profile) {
