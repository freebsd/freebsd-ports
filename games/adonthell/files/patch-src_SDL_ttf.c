--- src/SDL_ttf.c.orig	Wed Oct  4 16:00:53 2006
+++ src/SDL_ttf.c	Wed Oct  4 16:12:38 2006
@@ -43,7 +43,7 @@
 #include FT_FREETYPE_H
 #include FT_OUTLINE_H
 #include FT_TRUETYPE_IDS_H
-#include FT_INTERNAL_OBJECTS_H
+/* #include FT_INTERNAL_OBJECTS_H */
 
 #include "SDL.h"
 #include "SDL_endian.h"
@@ -270,7 +270,7 @@
 	}
 	memset(stream, 0, sizeof(*stream));
 
-	stream->memory = library->memory;
+	stream->memory = NULL;
 	stream->read = RWread;
 	stream->descriptor.pointer = src;
 	stream->pos = (unsigned long)position;
