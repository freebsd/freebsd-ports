--- src/cd-drive.c.orig	Mon Dec  8 22:08:56 2003
+++ src/cd-drive.c	Fri Jan 23 10:49:43 2004
@@ -65,7 +65,7 @@
 
 /* For dvd_plus_rw_utils.cpp */
 int get_dvd_r_rw_profile (const char *name);
-int get_mmc_profile (void *fd);
+int get_mmc_profile (int fd);
 
 static void
 add_dvd_plus (CDDrive *cdrom)
@@ -99,7 +99,7 @@
 		return CD_MEDIA_TYPE_ERROR;
 	}
 
-	mmc_profile = get_mmc_profile ((void *)&fd);
+	mmc_profile = get_mmc_profile (fd);
 	close (fd);
 
 	switch (mmc_profile) {
@@ -790,7 +790,11 @@
 		struct cam_device *cam_dev;
 
 		type = 0;
+#if defined(__FreeBSD__) && (__FreeBSD_version > 500000)
+		cam_path = g_strdup_printf ("/dev/%s%d", dev_type, i);
+#else
 		cam_path = g_strdup_printf ("/dev/%s%dc", dev_type, i);
+#endif
 
 		if (!g_file_test (cam_path, G_FILE_TEST_EXISTS)) {
 			g_free (cam_path);
@@ -803,29 +807,18 @@
 			continue;
 		}
 
-		/* XXX Other controllers might need to be added. */
-		if ((strncmp (cam_dev->sim_name, "ata", 3)) == 0) {
-			dev = g_strdup_printf ("/dev/a%s%dc", dev_type, i);
-		} else {
-			dev = g_strdup (cam_path);
-		}
+		dev = g_strdup (cam_path);
 
 		g_free (cam_path);
 
-		if ((fd = open (dev, O_RDWR, 0)) < 0) {
-			g_free (dev);
-			free (cam_dev);
-			i++;
-			continue;
-		}
-
-		type |= CDDRIVE_TYPE_CD_DRIVE;
-		if (ioctl (fd, CDRIOCWRITESPEED, &max_speed) >= 0) {
-			/* XXX is it CD-R or CD-RW ? */
-			type |= CDDRIVE_TYPE_CD_RECORDER;
+		if ((fd = open (dev, O_RDWR, 0)) >= 0) {
+			type |= CDDRIVE_TYPE_CD_DRIVE;
+			if (ioctl (fd, CDRIOCWRITESPEED, &max_speed) >= 0) {
+				/* XXX is it CD-R or CD-RW ? */
+				type |= CDDRIVE_TYPE_CD_RECORDER;
+			}
+			close (fd);
 		}
-
-		close (fd);
 
 		if (type & CDDRIVE_TYPE_CD_RECORDER
 				|| type & CDDRIVE_TYPE_CDRW_RECORDER
