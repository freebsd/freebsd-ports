--- aisleriot/sol.c.orig	Tue Nov 25 15:31:30 2003
+++ aisleriot/sol.c	Tue Nov 25 15:57:59 2003
@@ -83,6 +83,15 @@
 #define DEFAULT_VARIATION "klondike.scm"
 #define GNOME_SESSION_BUG
 
+gchar* game_file_to_variation (const gchar* file)
+{
+  char* p, *buf = g_path_get_basename(file);
+
+  if ((p = strrchr (buf, '.'))) *p = '\0';
+  
+  return buf;
+}  
+
 gchar* game_file_to_name (const gchar* file)
 {
   char* p, *buf = g_path_get_basename(file);
@@ -540,14 +549,14 @@
 	  n_games = 0;
 
   for (i = 0; i < n_games; i++) {
-    gchar *game_name = game_file_to_name (game_dents[i]->d_name);
-    if (!strcasecmp (variation, game_name)) {
+    gchar *game_variation = game_file_to_variation (game_dents[i]->d_name);
+    if (!strcasecmp (variation, game_variation)) {
       dont_save = TRUE;
       start_game = g_strdup ((gchar*) game_dents[i]->d_name);
-      g_free (game_name);
+      g_free (game_variation);
       break;
     }
-    g_free (game_name);
+    g_free (game_variation);
   }
   
   gh_enter(argc, argv, main_prog);
