--- src/WP_Image.C.orig	Sat May  4 00:49:18 2002
+++ src/WP_Image.C	Tue Nov 19 01:11:28 2002
@@ -154,7 +154,7 @@
       //read file to memory
 
       int size = 0;
-      byte c;
+      char c;
       while(input.get(c))
 	{
 	  size++;
@@ -434,7 +434,7 @@
       //read file to memory
 
       int size = 0;
-      byte c;
+      char c;
       while(input.get(c))
 	{
 	  size++;
@@ -460,7 +460,7 @@
 
       while(input.get(c))
 	{
-	  *p = c;
+	  *p = (byte)c;
 	  p++;
 	}
 
@@ -717,8 +717,8 @@
     }
 }
 
-void WP_Image::setTextureGL(GLuint* texture_id, GLint wrap_s=GL_REPEAT, GLint wrap_t=GL_REPEAT, 
-			    GLint mag_filter=GL_NEAREST, GLint min_filter=GL_NEAREST, bool mipmapping=false)
+void WP_Image::setTextureGL(GLuint* texture_id, GLint wrap_s, GLint wrap_t, 
+			    GLint mag_filter, GLint min_filter, bool mipmapping)
 {
   glGenTextures(1, texture_id);
   glBindTexture(GL_TEXTURE_2D, *texture_id);
