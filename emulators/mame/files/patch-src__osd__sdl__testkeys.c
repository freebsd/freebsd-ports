--- src/osd/sdl/testkeys.c.orig
+++ src/osd/sdl/testkeys.c
@@ -146,7 +146,6 @@
 				printf("ITEM_ID_XY %s 0x%x 0x%x %s\n",
 					lookup_key_name(sdl_lookup, event.key.keysym.scancode),
 					(int) event.key.keysym.scancode,
-					(int) event.key.keysym.unicode,
 					"");
 				lasttext[0] = 0;
 #else
@@ -165,7 +164,6 @@
 			printf("ITEM_ID_XY %s 0x%x 0x%x %s\n",
 					lookup_key_name(sdl_lookup, event.key.keysym.scancode),
 					(int) event.key.keysym.scancode,
-					(int) event.key.keysym.unicode,
 					lasttext);
 #else
 			memset(buf, 0, 19);
