--- gl_texture.c.orig	2021-02-09 17:35:52 UTC
+++ gl_texture.c
@@ -417,7 +417,7 @@ static void GL_Upload32 (unsigned *data, int width, in
 
 static void GL_Upload8 (byte *data, int width, int height, int mode) 
 {
-	static unsigned trans[640 * 480];
+	static unsigned trans[8192 * 8192];
 	int	i, image_size, p;
 	unsigned *table;
 
