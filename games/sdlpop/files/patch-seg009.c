--- seg009.c.orig	2018-03-17 16:33:14 UTC
+++ seg009.c
@@ -192,7 +192,7 @@ static FILE* open_dat_from_root_or_data_
 	// if failed, try if the DAT file can be opened in the data/ directory, instead of the main folder
 	if (fp == NULL) {
 		char data_path[POP_MAX_PATH];
-		snprintf(data_path, sizeof(data_path), "data/%s", filename);
+		snprintf(data_path, sizeof(data_path), "%%DATADIR%%/%s", filename);
 
         if (!file_exists(data_path)) {
             find_exe_dir();
@@ -1755,7 +1755,7 @@ const int max_sound_id = 58;
 char** sound_names = NULL;
 
 void load_sound_names() {
-	const char* names_path = locate_file("data/music/names.txt");
+	const char* names_path = locate_file("%%DATADIR%%/music/names.txt");
 	if (sound_names != NULL) return;
 	FILE* fp = fopen(names_path,"rt");
 	if (fp==NULL) return;
@@ -1805,7 +1805,7 @@ sound_buffer_type* load_sound(int index)
 					fp = fopen(filename, "rb");
 				}
 				if (fp == NULL && !skip_normal_data_files) {
-					snprintf(filename, sizeof(filename), "data/music/%s.ogg", sound_name(index));
+					snprintf(filename, sizeof(filename), "%%DATADIR%%/music/%s.ogg", sound_name(index));
 					fp = fopen(locate_file(filename), "rb");
 				}
 				if (fp == NULL) {
@@ -2108,7 +2108,7 @@ void __pascal far set_gr_mode(byte grmod
 	SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
 #endif
 	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_NOPARACHUTE |
-	             SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC ) != 0) {
+	             SDL_INIT_GAMECONTROLLER) != 0) {
 		sdlperror("SDL_Init");
 		quit(1);
 	}
@@ -2147,7 +2147,7 @@ void __pascal far set_gr_mode(byte grmod
 #endif
 	}
 
-	SDL_Surface* icon = IMG_Load(locate_file("data/icon.png"));
+	SDL_Surface* icon = IMG_Load(locate_file("%%DATADIR%%/icon.png"));
 	if (icon == NULL) {
 		sdlperror("Could not load icon");
 	} else {
@@ -2364,7 +2364,7 @@ void load_from_opendats_metadata(int res
 			if (len >= 5 && filename_no_ext[len-4] == '.') {
 				filename_no_ext[len-4] = '\0'; // terminate, so ".DAT" is deleted from the filename
 			}
-			snprintf(image_filename,sizeof(image_filename),"data/%s/res%d.%s",filename_no_ext, resource_id, extension);
+			snprintf(image_filename,sizeof(image_filename),"%%DATADIR%%/%s/res%d.%s",filename_no_ext, resource_id, extension);
 			if (!use_custom_levelset) {
 				//printf("loading (binary) %s",image_filename);
 				fp = fopen(locate_file(image_filename), "rb");
