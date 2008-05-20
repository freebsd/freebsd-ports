--- blight_input/SDL_ttf.c	2007-10-08 01:36:42.000000000 -0500
+++ blight_input/SDL_ttf.c	2007-10-08 01:39:03.000000000 -0500
@@ -48,7 +48,6 @@
 #include <freetype/ftoutln.h>
 #include <freetype/ttnameid.h>
 */
-#include <freetype/internal/ftobjs.h>
 
 #ifndef FT_OPEN_STREAM
 #define FT_OPEN_STREAM ft_open_stream
@@ -275,7 +274,7 @@
 	}
 	memset(stream, 0, sizeof(*stream));
 
-	stream->memory = library->memory;
+	stream->memory = NULL;
 	stream->read = RWread;
 	stream->descriptor.pointer = src;
 	stream->pos = (unsigned long)position;
