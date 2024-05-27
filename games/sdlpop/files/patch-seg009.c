--- seg009.c.orig	2023-02-04 09:43:22 UTC
+++ seg009.c
@@ -340,7 +340,7 @@ static FILE* open_dat_from_root_or_data_dir(const char
 	// if failed, try if the DAT file can be opened in the data/ directory, instead of the main folder
 	if (fp == NULL) {
 		char data_path[POP_MAX_PATH];
-		snprintf_check(data_path, sizeof(data_path), "data/%s", filename);
+		snprintf_check(data_path, sizeof(data_path), "%%DATADIR%%/%s", filename);
 
 		if (!file_exists(data_path)) {
 			find_exe_dir();
@@ -411,7 +411,7 @@ dat_type* open_dat(const char* filename, int optional)
 			filename_no_ext[len-4] = '\0'; // terminate, so ".DAT" is deleted from the filename
 		}
 		char foldername[POP_MAX_PATH];
-		snprintf_check(foldername,sizeof(foldername),"data/%s",filename_no_ext);
+		snprintf_check(foldername,sizeof(foldername),"%%DATADIR%%/%s",filename_no_ext);
 		const char* data_path = locate_file(foldername);
 		struct stat path_stat;
 		int result = stat(data_path, &path_stat);
@@ -2120,7 +2120,7 @@ void load_sound_names() {
 const int max_sound_id = 58;
 
 void load_sound_names() {
-	const char* names_path = locate_file("data/music/names.txt");
+	const char* names_path = locate_file("%%DATADIR%%/music/names.txt");
 	if (sound_names != NULL) return;
 	FILE* fp = fopen(names_path,"rt");
 	if (fp==NULL) return;
@@ -2170,7 +2170,7 @@ sound_buffer_type* load_sound(int index) {
 					fp = fopen(filename, "rb");
 				}
 				if (fp == NULL && !skip_normal_data_files) {
-					snprintf_check(filename, sizeof(filename), "data/music/%s.ogg", sound_name(index));
+					snprintf_check(filename, sizeof(filename), "%%DATADIR%%/music/%s.ogg", sound_name(index));
 					fp = fopen(locate_file(filename), "rb");
 				}
 				if (fp == NULL) {
@@ -2546,7 +2546,7 @@ void set_gr_mode(byte grmode) {
 #endif
 	}
 
-	SDL_Surface* icon = IMG_Load(locate_file("data/icon.png"));
+	SDL_Surface* icon = IMG_Load(locate_file("%%DATADIR%%/icon.png"));
 	if (icon == NULL) {
 		sdlperror("set_gr_mode: Could not load icon");
 	} else {
@@ -2814,7 +2814,7 @@ void load_from_opendats_metadata(int resource_id, cons
 			if (len >= 5 && filename_no_ext[len-4] == '.') {
 				filename_no_ext[len-4] = '\0'; // terminate, so ".DAT" is deleted from the filename
 			}
-			snprintf_check(image_filename,sizeof(image_filename),"data/%s/res%d.%s",filename_no_ext, resource_id, extension);
+			snprintf_check(image_filename,sizeof(image_filename),"%%DATADIR%%/%s/res%d.%s",filename_no_ext, resource_id, extension);
 			if (!use_custom_levelset) {
 				//printf("loading (binary) %s",image_filename);
 				fp = fopen(locate_file(image_filename), "rb");
