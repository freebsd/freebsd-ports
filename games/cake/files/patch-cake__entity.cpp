--- cake/entity.cpp.orig	Fri Jul 16 16:55:56 2004
+++ cake/entity.cpp	Fri Jul 16 16:56:20 2004
@@ -1534,10 +1534,10 @@
 			break;
 		case ET_TARGET_TELEPORTER:
 		case ET_TRIGGER_TELEPORT:
-			noise_index = loadSound("sound/world/telein.wav", false, false);
+			noise_index = loadSound("sound/world/telein.wav", NULL, false);
 			break;
 		case ET_TRIGGER_PUSH:
-			noise_index = loadSound("sound/world/jumppad.wav", false, false);
+			noise_index = loadSound("sound/world/jumppad.wav", NULL, false);
 			break;
 		default:
 			break;
