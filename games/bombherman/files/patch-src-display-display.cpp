--- src/display/display.cpp.orig	2012-05-26 11:11:52.000000000 +0200
+++ src/display/display.cpp	2013-09-17 10:22:23.000000000 +0200
@@ -20,7 +20,7 @@
 #include "display.hpp"
 
 #include <sstream>
-#include <librsvg/rsvg-cairo.h>
+#include <librsvg/rsvg.h>
 #include <cairo.h>
 
 #include "game/player.hpp"
@@ -116,7 +116,9 @@
 		throw exceptions::display::NoSDLException("Can't init use of TrueType fonts");
 	}
 	
-	g_type_init();
+	#if !GLIB_CHECK_VERSION(2,35,0)
+		g_type_init();
+	#endif
 	
 	setMode();
 }
