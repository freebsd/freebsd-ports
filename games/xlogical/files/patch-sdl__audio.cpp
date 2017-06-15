--- sdl_audio.cpp.orig	2001-07-31 20:54:55 UTC
+++ sdl_audio.cpp
@@ -27,6 +27,7 @@
 #endif
 
 #include <iostream>
+#include <cassert>
 #include <stdlib.h>
 
 #include <SDL.h>
@@ -58,13 +59,13 @@ get_music_info(
 	char *start, *end;
 	int len = strlen( aPath );
 
-	for( end=aPath+len; end >= 0; end-=1 )
+	for( end=aPath+len; *end != '.'; end-=1 )
 	{
-		if (*end == '.') break;
+		assert(end > aPath); // make sure we don't go past the string boundary
 	}
-	for( start=end; start >= 0; start-=1 )
+	for( start=end; *start != *PATHSEP; start-=1 )
 	{
-		if (*start == *PATHSEP) break;
+		assert(start > aPath); // make sure we don't go past the string boundary
 	}
 	char *buf = new char[len+1];
 	strncpy( buf, start+1, end-start-1 );
