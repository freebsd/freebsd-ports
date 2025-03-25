--- src/af/gr/xp/gr_CairoGraphics.cpp.orig	2021-07-03 15:46:07 UTC
+++ src/af/gr/xp/gr_CairoGraphics.cpp
@@ -535,7 +535,7 @@ void GR_CairoGraphics::drawGlyph(UT_uint32 Char, UT_si
 
 void GR_CairoGraphics::drawGlyph(UT_uint32 Char, UT_sint32 xoff, UT_sint32 yoff)
 {
-	drawChars(&Char, 0, 1, xoff, yoff, NULL);
+	drawChars(reinterpret_cast<const UT_UCSChar*>(&Char), 0, 1, xoff, yoff, NULL);
 }
 
 void GR_CairoGraphics::setColorSpace(GR_Graphics::ColorSpace /* c */)
