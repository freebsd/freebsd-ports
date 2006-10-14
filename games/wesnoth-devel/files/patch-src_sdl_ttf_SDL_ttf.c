--- src/sdl_ttf/SDL_ttf.c.orig	Wed Oct  4 16:45:59 2006
+++ src/sdl_ttf/SDL_ttf.c	Wed Oct  4 16:46:32 2006
@@ -48,7 +48,6 @@
 #include <freetype/ftoutln.h>
 #include <freetype/ttnameid.h>
 */
-#include <freetype/internal/ftobjs.h>
 
 #ifndef FT_OPEN_STREAM
 #define FT_OPEN_STREAM ft_open_stream
@@ -282,7 +281,7 @@
 	}
 	memset(stream, 0, sizeof(*stream));
 
-	stream->memory = library->memory;
+	stream->memory = NULL;
 	stream->read = RWread;
 	stream->descriptor.pointer = src;
 	stream->pos = (unsigned long)position;
