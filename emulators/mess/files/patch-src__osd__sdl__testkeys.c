--- src/osd/sdl/testkeys.c.orig	2013-10-30 21:16:48.577335486 +0100
+++ src/osd/sdl/testkeys.c	2013-10-30 21:27:06.551455870 +0100
@@ -146,7 +146,7 @@
 				printf("ITEM_ID_XY %s 0x%x 0x%x %s\n",
 					lookup_key_name(sdl_lookup, event.key.keysym.scancode),
 					(int) event.key.keysym.scancode,
-					(int) event.key.keysym.unicode,
+					(int) event.key.keysym.mod,
 					"");
 				lasttext[0] = 0;
 #else
@@ -155,7 +155,7 @@
 				printf("ITEM_ID_XY %s 0x%x 0x%x %s\n",
 					lookup_key_name(sdl_lookup, event.key.keysym.sym),
 					(int) event.key.keysym.scancode,
-					(int) event.key.keysym.unicode,
+					(int) event.key.keysym.mod,
 					buf);
 #endif
 			}
@@ -165,7 +165,7 @@
 			printf("ITEM_ID_XY %s 0x%x 0x%x %s\n",
 					lookup_key_name(sdl_lookup, event.key.keysym.scancode),
 					(int) event.key.keysym.scancode,
-					(int) event.key.keysym.unicode,
+					(int) event.key.keysym.mod,
 					lasttext);
 #else
 			memset(buf, 0, 19);
@@ -173,7 +173,7 @@
 			printf("ITEM_ID_XY %s 0x%x 0x%x %s\n",
 					lookup_key_name(sdl_lookup, event.key.keysym.sym),
 					(int) event.key.keysym.scancode,
-					(int) event.key.keysym.unicode,
+					(int) event.key.keysym.mod,
 					buf);
 #endif
 			break;
