--- Combiner.cpp.orig	Tue Sep 21 16:59:01 2004
+++ Combiner.cpp	Tue Sep 21 16:59:37 2004
@@ -348,7 +348,7 @@
 void Combiner_SelectCombine( u64 mux )
 {
 	// Hack for the Banjo-Tooie shadow (framebuffer textures must be enabled too)
-	if ((gDP.otherMode.cycleType == G_CYC_1CYCLE) && (mux == 0x00ffe7ffffcf9fcf) && (cache.current[0]->frameBufferTexture))
+	if ((gDP.otherMode.cycleType == G_CYC_1CYCLE) && (mux == 0x00ffe7ffffcf9fcfLL) && (cache.current[0]->frameBufferTexture))
 	{
 		mux = EncodeCombineMode( 0, 0, 0, 0, TEXEL0, 0, PRIMITIVE, 0,
 								 0, 0, 0, 0, TEXEL0, 0, PRIMITIVE, 0 );
