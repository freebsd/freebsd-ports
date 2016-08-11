--- main.c.orig	2016-06-14 16:25:53 UTC
+++ main.c
@@ -38,6 +38,7 @@
 #include "main.h"
 #include "edit.h"
 #include "shooter.h"
+#include "unix.h"
 
 #include "../data/data.h"
 
@@ -66,7 +67,6 @@ PALETTE org_pal;
 Tscroller hscroll;
 Thisc *hisc_table;
 Thisc *hisc_table_space;
-char working_directory[1024];
 
 // the map
 Tmap *map = NULL;
@@ -126,6 +126,7 @@ int menu_choice = 1;
 int playing_original_game = 1;
 int init_ok = 0;
 
+static FILE* log_fp = NULL;
 
 
 // // // // // // // // // // // // // // // // // // // // // 
@@ -154,20 +155,18 @@ char *get_init_string() {
 // loggs the text to the text file
 void log2file(char *format, ...) {
 	va_list ptr; /* get an arg pointer */
- 	FILE *fp;
 	
-	fp = fopen("log.txt", "at");
-	if (fp) {
+	if (log_fp) {
 		/* initialize ptr to point to the first argument after the format string */
 		va_start(ptr, format);
  
 		/* Write to logfile. */
-		vfprintf(fp, format, ptr); // Write passed text.
-		fprintf(fp, "\n"); // New line..
+		vfprintf(log_fp, format, ptr); // Write passed text.
+		fprintf(log_fp, "\n"); // New line..
  
 		va_end(ptr);
  
-		fclose(fp);
+		fflush(log_fp);
 	}
 
 }
@@ -618,6 +617,10 @@ int init_game(const char *map_file) {
 	BITMAP *bmp;
 	int i;
 	int w, h;
+#ifdef __unix__   
+	char filename[512];
+	char *homedir = get_homedir();
+#endif 	
 
 	log2file("\nInit routines:");
 
@@ -625,7 +628,13 @@ int init_game(const char *map_file) {
 	log2file(" initializing allegro");
 	text_mode(-1);
 	garble_string(init_string, 53);
+#ifdef __unix__
+	snprintf(filename, sizeof(filename), "%s/.alex4/alex4.ini",
+		homedir? homedir:".");
+	override_config_file(filename);
+#else
 	set_config_file("alex4.ini");
+#endif
 	set_window_close_button(FALSE);
 	
 	// install timers
@@ -695,6 +704,7 @@ int init_game(const char *map_file) {
 	textout_centre(swap_screen, font, "loading...", 320, 200, 1);
 	blit_to_screen(swap_screen);
 
+#ifndef __unix__
 	// set switch modes and callbacks
 	if (set_display_switch_mode(SWITCH_PAUSE) < 0)
 		log2file("  * display switch mode failed");
@@ -702,6 +712,7 @@ int init_game(const char *map_file) {
 		log2file("  * display switch in failed");
 	if (set_display_switch_callback(SWITCH_OUT, display_switch_out) < 0)
 		log2file("  * display switch out failed");
+#endif
 
 
 	// set win title (no! really???)
@@ -718,7 +729,7 @@ int init_game(const char *map_file) {
 	// load data
 	log2file(" loading data");
 	packfile_password(init_string);
-	data = load_datafile("data/data.dat");
+	data = load_datafile(DATADIR "data.dat");
 	packfile_password(NULL);
 	if (data == NULL) {
     	log2file("  *** failed");
@@ -728,7 +739,13 @@ int init_game(const char *map_file) {
 
 	// load options
 	log2file(" loading options");
+#ifdef __unix__
+	snprintf(filename, sizeof(filename), "%s/.alex4/alex4.sav",
+		homedir? homedir:".");
+	pf = pack_fopen(filename, "rp");
+#else
 	pf = pack_fopen("alex4.sav", "rp");
+#endif
 	if (pf) {
 		load_options(&options, pf);
 		pack_fclose(pf);
@@ -740,7 +757,13 @@ int init_game(const char *map_file) {
 
 	// loading highscores
 	log2file(" loading hiscores");
+#ifdef __unix__
+	snprintf(filename, sizeof(filename), "%s/.alex4/alex4.hi",
+		homedir? homedir:".");
+	pf = pack_fopen(filename, "rp");
+#else
 	pf = pack_fopen("alex4.hi", "rp");
+#endif
 	if (pf) {
 		load_hisc_table(hisc_table, pf);
 		load_hisc_table(hisc_table_space, pf);
@@ -776,7 +799,7 @@ int init_game(const char *map_file) {
 		log2file(" loading original maps");
 		packfile_password(init_string);
 		num_levels = -1;  // skip end object when counting
-		maps = load_datafile_callback("data/maps.dat", count_maps_callback);
+		maps = load_datafile_callback(DATADIR "maps.dat", count_maps_callback);
 		packfile_password(NULL);
 		if (maps == NULL) {
 	    	log2file("  *** failed");
@@ -835,11 +858,12 @@ int init_game(const char *map_file) {
 	// install sound
 	log2file(" installing sound");
    	set_volume_per_voice(0);
-	switch(get_config_int("sound", "sound_device", 0)) {
+	switch(get_config_int("sound", "sound_device", 1)) {
 		case 1:
 			i = DIGI_AUTODETECT;
 			log2file("  DIGI_AUTODETECT selected (%d)", i);
 			break;
+#ifdef ALLEGRO_WINDOWS
 		case 2:
 			i = DIGI_DIRECTX(0);
 			log2file("  DIGI_DIRECTX(0) selected (%d)", i);
@@ -848,6 +872,20 @@ int init_game(const char *map_file) {
 			i = DIGI_DIRECTAMX(0);
 			log2file("  DIGI_DIRECTAMX(0) selected (%d)", i);
 			break;
+#elif defined ALLEGRO_UNIX
+#ifdef DIGI_OSS
+		case 2:
+			i = DIGI_OSS;
+			log2file("  DIGI_OSS selected (%d)", i);
+			break;
+#endif
+#ifdef DIGI_ALSA
+		case 3:
+			i = DIGI_ALSA;
+			log2file("  DIGI_ALSA selected (%d)", i);
+			break;
+#endif
+#endif
 		default:
 			i = -770405;	// dummy number
 			got_sound = 0;
@@ -870,9 +908,9 @@ int init_game(const char *map_file) {
 		if (get_config_int("sound", "use_sound_datafile", 1)) {
 			log2file(" loading sound datafile");
 			packfile_password(init_string);
-			sfx_data = load_datafile("data/sfx_44.dat");
+			sfx_data = load_datafile(DATADIR "sfx_44.dat");
 			if (sfx_data == NULL) {
-				sfx_data = load_datafile("data/sfx_22.dat");
+				sfx_data = load_datafile(DATADIR "sfx_22.dat");
 				log2file("  sfx_44.dat not found");
 				s = 0;
 			}
@@ -971,6 +1009,10 @@ int init_game(const char *map_file) {
 void uninit_game() {
 	int i;
 	PACKFILE *pf;
+#ifdef __unix__   
+	char filename[512];
+	char *homedir = get_homedir();
+#endif 	
 
 	log2file("\nExit routines:");
 
@@ -989,14 +1031,26 @@ void uninit_game() {
 	// only save if everything was inited ok!
 	if (init_ok) {
 		log2file(" saving options");
+#ifdef __unix__
+		snprintf(filename, sizeof(filename), "%s/.alex4/alex4.sav",
+			homedir? homedir:".");
+		pf = pack_fopen(filename, "wp");
+#else
 		pf = pack_fopen("alex4.sav", "wp");
+#endif
 		if (pf) {
 			save_options(&options, pf);
 			pack_fclose(pf);
 		}
 		
 		log2file(" saving highscores");
+#ifdef __unix__
+		snprintf(filename, sizeof(filename), "%s/.alex4/alex4.hi",
+			homedir? homedir:".");
+		pf = pack_fopen(filename, "wp");
+#else
 		pf = pack_fopen("alex4.hi", "wp");
+#endif
 		if (pf) {
 			save_hisc_table(hisc_table, pf);
 			save_hisc_table(hisc_table_space, pf);
@@ -1289,7 +1343,7 @@ void show_cutscene(int level) {
 			// poll music machine
 			if (got_sound) al_poll_duh(dp);
 
-			if (mode == 1 && (keypressed() || is_fire(&ctrl) || is_jump(&ctrl) ) || my_counter > 200) {
+			if (((mode == 1) && (keypressed() || is_fire(&ctrl) || is_jump(&ctrl))) || (my_counter > 200)) {
 				mode = 2;
 			}
 			
@@ -1343,7 +1397,7 @@ void show_scores(int space, Thisc *table
 	if (space) {
 		// get space bg
 		packfile_password(init_string);
-		df = load_datafile_object("data/a45.dat", "BG1");
+		df = load_datafile_object(DATADIR "a45.dat", "BG1");
 		packfile_password(NULL);
 		if (df != NULL)	{
 			bg = df->dat;
@@ -2149,7 +2203,7 @@ void check_alex_with_enemies() {
 
 // calculates camera pos for map m considering player p
 void calculate_camera_pos(Tplayer *p, Tmap *m) {
-	static camera_type = 1;
+	static int camera_type = 1;
 
 	if (p->actor->status == AC_BALL) {
 		camera_type = 2;
@@ -2841,6 +2895,10 @@ int do_main_menu() {
 			}
 			else {
 				PACKFILE *pf;
+#ifdef __unix__   
+				char filename[512];
+				char *homedir = get_homedir();
+#endif 	
 				log2file(" level complete");
 				if (got_sound) stop_music();
 				if (level < MAX_LEVELS && playing_original_game) {
@@ -2875,7 +2933,14 @@ int do_main_menu() {
 
 				// save options
 				log2file(" saving options");
+#ifdef __unix__
+				snprintf(filename, sizeof(filename),
+					"%s/.alex4/alex4.sav",
+					homedir? homedir:".");
+				pf = pack_fopen(filename, "wp");
+#else
 				pf = pack_fopen("alex4.sav", "wp");
+#endif
 				if (pf) {
 					save_options(&options, pf);
 					pack_fclose(pf);
@@ -2969,24 +3034,36 @@ int do_main_menu() {
 
 // main
 int main(int argc, char **argv) {   
-	FILE *fp;
 	int i;
 	char full_path[1024];
+#ifndef __unix__   
+	char working_directory[1024];
+#else
+	char *homedir = get_homedir();
+#endif
 
 	// init allegro
 	allegro_init();
 
+#ifdef __unix__
+	// start logfile
+	snprintf(full_path, sizeof(full_path), "%s/.alex4",
+		homedir? homedir:".");
+	check_and_create_dir(full_path);
+	snprintf(full_path, sizeof(full_path), "%s/.alex4/log.txt",
+		homedir? homedir:".");
+	log_fp = fopen(full_path, "wt");
+#else
 	// get working directory
 	get_executable_name(full_path, 1024);
 	replace_filename(working_directory, full_path, "", 1024);
 	chdir(working_directory);
 
-
 	// start logfile
-	fp = fopen("log.txt", "wt");
-	if (fp) {
-		fprintf(fp, "Alex 4 (%s) - log file\n-------------------\n", GAME_VERSION_STR);
-		fclose(fp);
+	log_fp = fopen("log.txt", "wt");
+#endif
+	if (log_fp) {
+		fprintf(log_fp, "Alex 4 (%s) - log file\n-------------------\n", GAME_VERSION_STR);
 	}
 
 	// log program arguments
@@ -2994,7 +3071,9 @@ int main(int argc, char **argv) {   
 	for(i = 0; i < argc; i ++) {
 		log2file("   %s", argv[i]);
 	}
+#ifndef __unix__
 	log2file("Working directory is:\n   %s", working_directory);
+#endif
 
 	// test wether to play real game
 	// or custom levels
@@ -3022,6 +3101,8 @@ int main(int argc, char **argv) {   
 	uninit_game();
 	allegro_exit();
 	log2file("\nDone...\n");
+	if (log_fp)
+		fclose(log_fp);
 
 	return 0;
 } END_OF_MAIN(); 
