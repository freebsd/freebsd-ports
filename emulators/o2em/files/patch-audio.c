--- ../o2em117src.old/src/audio.c	Sat Jun 25 13:41:39 2005
+++ ./src/audio.c	Sat Jun 25 13:42:08 2005
@@ -118,7 +118,7 @@
 			if (digi_driver->name && (strlen(digi_driver->name)>0)){
 				printf("  Sound system initialized ok\n");
 				printf("  Sound driver [%s] detected\n",digi_driver->name);
-				set_volume(255,255);
+				set_volume(-1,-1);
 				init_sound_stream();
 			} else {
 				printf("  ERROR: could not initialize sound card\n");
