--- src/cd-drive.c.orig	Sun Dec 24 22:45:32 2006
+++ src/cd-drive.c	Sun Dec 24 22:45:12 2006
@@ -82,6 +82,9 @@ struct CDDrivePriv {
 	char *udi;
 };
 
+static int get_device_max_read_speed (char *device);
+static int get_device_max_write_speed (char *device);
+
 static CDDrive *cd_drive_new (void);
 
 /* Utility functions, be careful to have a match with what's use in the
