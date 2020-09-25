--- main.c.orig	2008-08-08 08:48:38 UTC
+++ main.c
@@ -178,7 +178,7 @@ int process_files(FILE_LIST* file_list, SETTINGS* sett
 	/* Undo previously applied gain */
 	if (settings->undo) {
 		for (file = file_list; file; file = file->next_file) {
-			if (file->filename == '\0')
+			if (file->filename == NULL)
 				continue;
 			if (!write_gains(file->filename, 0, 0, 0, 0, 0, settings)) {
 				fprintf(stderr, " Error processing GAIN for file - %s\n", file->filename);
@@ -191,12 +191,12 @@ int process_files(FILE_LIST* file_list, SETTINGS* sett
 		for (file = file_list; file; file = file->next_file) {
 			int dc_l;
 			int dc_r;
-			if (file->filename == '\0')
+			if (file->filename == NULL)
 				continue;
 
 			if (!get_gain(file->filename, &file->track_peak, &file->track_gain,
 			              file->dc_offset, file->offset, settings)) {
-				file->filename = '\0';
+				file->filename = NULL;
 				continue;
 			}
 			dc_l = (int)(file->dc_offset[0] * 32768 * -1);
@@ -262,7 +262,7 @@ int process_files(FILE_LIST* file_list, SETTINGS* sett
 		if(settings->apply_gain) {	/* Write radio and audiophile gains. */
 			total_files = 0.0;
 			for (file = file_list; file; file = file->next_file) {
-				if (file->filename == '\0')
+				if (file->filename == NULL)
 					continue;
 				if (settings->audiophile && settings->set_album_gain == 1)
 					break;
@@ -297,7 +297,7 @@ int process_files(FILE_LIST* file_list, SETTINGS* sett
 		SetEnvironmentVariable("ALBUM_PEAK", ftos(settings->album_peak, "%.0lf"));
 
 		for (file = file_list; file; file = file->next_file) {
-			if (file->filename == '\0')
+			if (file->filename[0] == NULL)
 				continue;
 
 			if (dir[0] == '.' && dir[1] == '\\') dir += 2;
