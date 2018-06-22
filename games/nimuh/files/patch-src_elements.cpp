--- src/elements.cpp.orig	2007-12-26 16:33:04 UTC
+++ src/elements.cpp
@@ -773,7 +773,7 @@ namespace Martian {
 
 	void Frame::unLoad() {
 		glDeleteTextures( 1, &texture );
-		glBindTexture(GL_TEXTURE_2D,NULL); 
+		glBindTexture(GL_TEXTURE_2D,0); 
 	}
 
 	
