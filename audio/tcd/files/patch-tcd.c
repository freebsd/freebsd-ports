--- src/tcd.c.orig	2004-06-15 22:32:31.000000000 +0200
+++ src/tcd.c	2008-06-27 22:55:04.000000000 +0200
@@ -33,6 +33,7 @@
 #include <unistd.h>
 
 #include <SDL/SDL.h>
+#include <sys/cdio.h>
 
 #include "cd-utils.h"
 #include "cddb.h"
@@ -179,6 +180,26 @@
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
@@ -217,11 +238,11 @@
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
@@ -237,7 +258,7 @@
     state.play_method = NORMAL;
 
     init_SDL((argc > 1) ? strtol(argv[1], NULL, 0) : 0);
-    tcd_readdiskinfo(&state.cd_info, state.cdrom);
+    tcd_readdiskinfo(&state, state.cdrom);
     tcd_ui_init();
     tcd_ui_update(&state);
     state.current_discid = cddb_discid(state.cdrom);
@@ -262,6 +283,8 @@
             case 's': case 'S': handle_stop(); break;
             case ']': handle_skip_forward(); break;
             case '[': handle_skip_back(); break;
+	    case '*': inc_volume(); break;
+	    case '/': dec_volume(); break;
 	}
     }
     tcd_ui_shutdown();
