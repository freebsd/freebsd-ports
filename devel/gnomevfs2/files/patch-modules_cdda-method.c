--- modules/cdda-method.c.orig	Tue Jan 27 06:19:01 2004
+++ modules/cdda-method.c	Wed Jan 28 00:21:01 2004
@@ -623,7 +623,11 @@
 	/* Check and see if we already have opened and stashed this drive */
 	if (!use_base) {
 		if (global_context != NULL) {
+#ifdef Linux
 			if (strcmp (drive->cdda_device_name, global_context->drive->cdda_device_name) == 0) {
+#elif defined(__FreeBSD__)
+			if (strcmp (drive->dev->device_path, global_context->drive->dev->device_path) == 0) {
+#endif
 				use_cache = TRUE;
 				cdda_close (drive);
 				gnome_vfs_file_info_copy (file_info, global_context->file_info);
@@ -709,7 +713,11 @@
 	if (!use_base) {
 		/* Check for cache */
 		if (global_context != NULL) {
+#ifdef Linux
 				if (strcmp (drive->cdda_device_name, global_context->drive->cdda_device_name) != 0) {
+#elif defined(__FreeBSD__)
+				if (strcmp (drive->dev->device_path, global_context->drive->dev->device_path) != 0) {
+#endif
 					/*	Clear old cache */
 					cdda_context_free (global_context);
 					global_context = cdda_context_new (drive, uri);
