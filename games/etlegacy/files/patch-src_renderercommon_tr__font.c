--- src/renderercommon/tr_font.c.orig	2024-01-10 04:52:35 UTC
+++ src/renderercommon/tr_font.c
@@ -202,7 +202,7 @@ static glyphInfo_t *RE_ConstructGlyphInfo(int imageSiz
 
 		rc = FT_Load_Glyph(face, index, flags);
 
-		if (rc)
+		if (rc != 0)
 		{
 			Ren_Warning("RE_ConstructGlyphInfo: cannot load a glyph into the glyph slot of a face object.\n");
 			return &glyph;         // nothing to render
