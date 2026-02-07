- fix mistyped return statements, which clang objects strenuously to

--- plugins/morph/flash/morph_flash.c~	2006-01-27 20:19:18.000000000 +0000
+++ plugins/morph/flash/morph_flash.c
@@ -116,7 +116,7 @@ int lv_morph_flash_palette (VisPluginDat
 	FlashPrivate *priv = visual_object_get_private (VISUAL_OBJECT (plugin));
 
 	if (src1->pal == NULL || src2->pal == NULL)
-		return;
+		return 0;
 
 	if (rate < 0.5)
 		visual_palette_blend (pal, src1->pal, &priv->whitepal, rate * 2);
