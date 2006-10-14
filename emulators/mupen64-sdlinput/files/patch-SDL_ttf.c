--- src/SDL_ttf.c.orig	Tue Oct 14 20:44:17 2003
+++ src/SDL_ttf.c	Wed Oct  4 08:38:49 2006
@@ -39,10 +39,10 @@
 #define FREEA(p) free(p)
 #endif
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftoutln.h>
 #include <freetype/ttnameid.h>
-#include <freetype/internal/ftobjs.h>
 
 /** hack **/
 #ifndef ft_open_stream
@@ -272,7 +272,7 @@
 	}
 	memset(stream, 0, sizeof(*stream));
 
-	stream->memory = library->memory;
+	stream->memory = NULL;
 	stream->read = RWread;
 	stream->descriptor.pointer = src;
 	stream->pos = (unsigned long)position;
