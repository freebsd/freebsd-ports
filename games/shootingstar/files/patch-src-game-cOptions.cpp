--- src/game/cOptions.cpp.orig	Mon Dec 22 08:09:06 2003
+++ src/game/cOptions.cpp	Sun Nov 20 03:12:28 2005
@@ -201,7 +201,7 @@
 			dbgError () << "Unable to read from options file\n";
 			throw runtime_error ("Unable to load options");
 		}
-		int (keys.keys[i]) = key;	// IS THIS SAFE?
+		keys.keys[i] = (SDLKey)key;	// IS THIS SAFE?
 		
 		fin >> key;
 		keys.buttons[i] = key;
