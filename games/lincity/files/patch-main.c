--- main.c.orig	2004-07-03 07:59:05 UTC
+++ main.c
@@ -96,9 +96,9 @@ char LIBDIR[LC_PATH_MAX];
 #endif
 #endif
 
-char *lc_save_dir;
-char *lc_temp_file;
-char save_names[10][42];
+extern char *lc_save_dir;
+extern char *lc_temp_file;
+extern char save_names[10][42];
 
 #ifdef CS_PROFILE
 int prof_countdown = PROFILE_COUNTDOWN;
