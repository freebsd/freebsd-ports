--- glfont.c.orig	2015-10-13 20:12:27 UTC
+++ glfont.c
@@ -120,7 +120,7 @@ static FT_Face load_font(char *fontname)
         return face;
 }
 
-static FT_Face UNUSED_ATTR load_builtin_font(void *base, int len)
+static FT_Face UNUSED_ATTR load_builtin_font(const void *base, int len)
 {
         FT_Face face;
         int code;
