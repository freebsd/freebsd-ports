--- modexlib.c.orig	Wed Feb 18 08:29:15 2004
+++ modexlib.c	Wed Feb 18 08:29:58 2004
@@ -418,7 +418,7 @@
 	    Error ("Could not initialize SDL\n");
 	}
 
-    #if defined(PLATFORM_WIN32) || defined(PLATFORM_MACOSX)
+    #if defined(PLATFORM_WIN32) || defined(PLATFORM_MACOSX) || defined(PLATFORM_UNIX)
         // FIXME: remove this.  --ryan.
         flags = SDL_FULLSCREEN;
         SDL_WM_GrabInput(SDL_GRAB_ON);
