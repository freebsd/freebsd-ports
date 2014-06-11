--- ./src/core_lua.c.orig	2014-05-19 04:42:14.000000000 -0400
+++ ./src/core_lua.c	2014-06-04 12:40:26.921306625 -0400
@@ -416,7 +416,7 @@
 
 static int lua_key_set_clipboard(lua_State *L)
 {
-	char *str = luaL_checkstring(L, 1);
+	const char *str = luaL_checkstring(L, 1);
 	SDL_SetClipboardText(str);
 	return 0;
 }
@@ -1458,7 +1458,7 @@
 		);
 	SDL_FillRect(s, NULL, SDL_MapRGBA(s->format, 255, 255, 255, 255));
 
-	glGenTextures(1, &gl_tex_white);
+	glGenTextures(1, (GLuint *)&gl_tex_white);
 	tfglBindTexture(GL_TEXTURE_2D, gl_tex_white);
 	int fw, fh;
 	make_texture_for_surface(s, &fw, &fh, false);
@@ -2870,7 +2870,7 @@
 static void png_write_data_fn(png_structp png_ptr, png_bytep data, png_size_t length)
 {
 	luaL_Buffer *B = (luaL_Buffer*)png_get_io_ptr(png_ptr);
-	luaL_addlstring(B, data, length);
+	luaL_addlstring(B, (const char *)data, length);
 }
 static void png_output_flush_fn(png_structp png_ptr)
 {
@@ -3561,14 +3561,14 @@
 	uLongf len;
 	const char *data = luaL_checklstring(L, 1, (size_t*)&len);
 	uLongf reslen = len * 1.1 + 12;
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 	unsigned
 #endif
 	char *res = malloc(reslen);
 	z_stream zi;
 
 	zi.next_in = (
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 	unsigned
 #endif
 	char *)data;
