--- src/tcd.c.orig	2008-06-26 19:40:23.000000000 +0200
+++ src/tcd.c	2008-06-26 19:40:47.000000000 +0200
@@ -221,7 +221,7 @@
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
