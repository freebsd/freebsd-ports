--- src/tcd.c.orig	2004-06-15 22:32:31.000000000 +0200
+++ src/tcd.c	2008-07-04 20:09:09.000000000 +0200
@@ -33,6 +33,7 @@
 #include <unistd.h>
 
 #include <SDL/SDL.h>
+#include <sys/cdio.h>
 
 #include "cd-utils.h"
 #include "cddb.h"
@@ -134,11 +135,6 @@
     }
 }
 
-static void handle_repeat_track(void)
-{
-    state.play_method = REPEAT_TRK;
-}
-
 static void handle_eject(void)
 {
     SDL_CDEject(state.cdrom);
@@ -179,6 +175,26 @@
     }
 }
 
+static void inc_volume(void)
+{
+    struct ioc_vol arg;
+    if(ioctl(state.cdrom->id, CDIOCGETVOL, &arg) == -1)
+	return;
+    arg.vol[0] += arg.vol[0] > 250 ? 255 - arg.vol[0] : 5;
+    arg.vol[1] += arg.vol[1] > 250 ? 255 - arg.vol[1] : 5;
+    ioctl(state.cdrom->id, CDIOCSETVOL, &arg);
+}
+
+static void dec_volume(void)
+{
+    struct ioc_vol arg;
+    if(ioctl(state.cdrom->id, CDIOCGETVOL, &arg) == -1)
+	return;
+    arg.vol[0] -= arg.vol[0] < 5 ? arg.vol[0] : 5;
+    arg.vol[1] -= arg.vol[1] < 5 ? arg.vol[1] : 5;
+    ioctl(state.cdrom->id, CDIOCSETVOL, &arg);
+}
+
 static void init_SDL(int cdrom_num)
 {
     int err = SDL_Init(SDL_INIT_CDROM);
@@ -217,11 +233,11 @@
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
@@ -237,7 +253,7 @@
     state.play_method = NORMAL;
 
     init_SDL((argc > 1) ? strtol(argv[1], NULL, 0) : 0);
-    tcd_readdiskinfo(&state.cd_info, state.cdrom);
+    tcd_readdiskinfo(&state, state.cdrom);
     tcd_ui_init();
     tcd_ui_update(&state);
     state.current_discid = cddb_discid(state.cdrom);
@@ -255,13 +271,16 @@
             case '-': case '_': handle_prev_track(); break;
             case 'g': case 'G': handle_goto(); break;
             case 'c': case 'C': state.play_method = REPEAT_CD; break;
-            case 'r': case 'R': handle_repeat_track(); break;
+            case 'r': case 'R': state.play_method = REPEAT_TRK; break;
             case 'm': case 'M': handle_method(); break;
             case 'e': case 'E': handle_eject(); break;
             case 't': case 'T': handle_editor(); break;
-            case 's': case 'S': handle_stop(); break;
+            case 's': case 'S': state.play_method = NORMAL;
+                                handle_stop(); break;
             case ']': handle_skip_forward(); break;
             case '[': handle_skip_back(); break;
+            case '*': inc_volume(); break;
+            case '/': dec_volume(); break;
 	}
     }
     tcd_ui_shutdown();
