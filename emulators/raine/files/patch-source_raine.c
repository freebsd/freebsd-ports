--- source/raine.c.bak	Thu Nov 17 17:58:51 2005
+++ source/raine.c	Thu Nov 17 17:57:32 2005
@@ -92,6 +92,17 @@
 {
    int i,ta,version_id;
    char str[256],*s;
+   char *dirs[] = {
+		 "config",
+		 "savegame",
+		 "savedata",
+		 "roms",
+		 "demos",
+		 "snapshot",
+		 "artwork",
+		 NULL
+		 };
+   char **dirp = dirs;
 #ifdef GFX_FBCON
    FILE *f;
 #endif
@@ -241,18 +252,6 @@
    raine_cfg.hide = 0;
    raine_cfg.req_load_game = 0;
    raine_cfg.req_game_index = 0;
-
-   char *dirs[] = {
-		 "config",
-		 "savegame",
-		 "savedata",
-		 "roms",
-		 "demos",
-		 "snapshot",
-		 "artwork",
-		 NULL
-		 };
-   char **dirp = dirs;
 
    mkdir_rwx(dir_cfg.exe_path);
    while (*dirp) {
