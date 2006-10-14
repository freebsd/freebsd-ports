--- SDL_ttf.c.orig	Mon May  1 05:26:17 2006
+++ SDL_ttf.c	Sun Sep 24 15:46:44 2006
@@ -48,7 +48,6 @@
 #include <freetype/ftoutln.h>
 #include <freetype/ttnameid.h>
 */
-#include <freetype/internal/ftobjs.h>
 
 #ifndef FT_OPEN_STREAM
 #define FT_OPEN_STREAM ft_open_stream
@@ -278,7 +277,7 @@
 	}
 	memset(stream, 0, sizeof(*stream));
 
-	stream->memory = library->memory;
+	stream->memory = NULL;
 	stream->read = RWread;
 	stream->descriptor.pointer = src;
 	stream->pos = (unsigned long)position;
