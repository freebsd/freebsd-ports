--- libs/models/gl_skin.c.orig	2013-01-23 03:10:55 UTC
+++ libs/models/gl_skin.c
@@ -230,19 +230,20 @@ gl_Skin_SetupSkin (skin_t *skin, int cma
 	int         changed;
 	glskin_t   *s;
 
+	skin->texnum = 0;
+	skin->auxtex = 0;
+	if (!cmap) {
+		return;
+	}
 	// simplify cmap usage (texture offset/array index)
 	cmap--;
 	s = skins + cmap;
 	changed = (s->tex != skin->texels);
 	s->tex = skin->texels;
 	if (!changed) {
-		skin->texnum = 0;
-		skin->auxtex = 0;
-		if (cmap >= 0) {
-			skin->texnum = skin_textures + cmap;
-			if (s->fb)
-				skin->auxtex = skin_fb_textures + cmap;
-		}
+		skin->texnum = skin_textures + cmap;
+		if (s->fb)
+			skin->auxtex = skin_fb_textures + cmap;
 		return;
 	}
 	if (s->tex)
