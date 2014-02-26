--- vcl/headless/svptext.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ vcl/headless/svptext.cxx	2014-02-24 14:16:24.000000000 -0500
@@ -172,7 +172,7 @@
 
 void SvpGlyphPeer::RemovingGlyph( ServerFont&, GlyphData& rGlyphData, int /*nGlyphIndex*/ )
 {
-    if( rGlyphData.ExtDataRef().mpData != Format::NONE )
+    if( rGlyphData.ExtDataRef().mpData != 0 )
     {
         // release the glyph related resources
         DBG_ASSERT( (rGlyphData.ExtDataRef().meInfo <= Format::MAX), "SVP::RG() invalid alpha format" );
