--- src/subsim.cpp.orig	2007-06-11 15:16:23 UTC
+++ src/subsim.cpp
@@ -31,6 +31,7 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #else
 #include "oglext/OglExt.h"
 #endif
+#include <unistd.h>
 #include <glu.h>
 #include <SDL.h>
 #include <SDL_net.h>
@@ -1735,7 +1736,7 @@ int mymain(list<string>& args)
 	glEnable(GL_LIGHT0);
 
 	// create and start thread for music handling.
-	thread::auto_ptr<music> mmusic(new music(use_sound));
+	::thread::auto_ptr<music> mmusic(new music(use_sound));
 	mmusic->start();
 
 	reset_loading_screen();
