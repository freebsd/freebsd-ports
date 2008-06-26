--- src/tcd.c.orig	2004-06-15 22:32:31.000000000 +0200
+++ src/tcd.c	2008-06-27 01:25:01.000000000 +0200
@@ -217,11 +217,11 @@
 static void detect_disc_change(void)
 {
     unsigned long discid = cddb_discid(state.cdrom);
-    if (discid != state.current_discid) {
+    if (CD_INDRIVE(state.cdrom->status) && discid != state.current_discid) {
         if (state.cd_info.modified) {
             tcd_writediskinfo(&state.cd_info, state.cdrom);
         }
-        tcd_readdiskinfo(&state.cd_info, state.cdrom);
+        tcd_readdiskinfo(&state, state.cdrom);
         state.current_discid = discid;
     }
 }
@@ -237,7 +237,7 @@
     state.play_method = NORMAL;
 
     init_SDL((argc > 1) ? strtol(argv[1], NULL, 0) : 0);
-    tcd_readdiskinfo(&state.cd_info, state.cdrom);
+    tcd_readdiskinfo(&state, state.cdrom);
     tcd_ui_init();
     tcd_ui_update(&state);
     state.current_discid = cddb_discid(state.cdrom);
