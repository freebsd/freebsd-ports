--- src/af/xap/unix/xap_UnixFont.cpp.orig	Mon Aug  4 20:24:53 2003
+++ src/af/xap/unix/xap_UnixFont.cpp	Mon Aug  4 20:25:50 2003
@@ -400,10 +400,10 @@
 	size_t idx = 0;
 	for (size_t i = 0; i < coverage.size(); i += 2)
 	  {
-		  UT_UCSChar c1 = static_cast<UT_UCSChar>(reinterpret_cast<UT_uint32>(coverage[i]));
+		  UT_UCSChar c1 = static_cast<UT_UCSChar>(reinterpret_cast<unsigned long>(coverage[i]));
 		  UT_UCSChar c2 =
 			  static_cast<UT_UCSChar>(static_cast<UT_uint32>(c1)) +
-			  static_cast<UT_UCSChar>(reinterpret_cast<UT_uint32>(coverage[i + 1]));
+			  static_cast<UT_UCSChar>(reinterpret_cast<unsigned long>(coverage[i + 1]));
 		  for (UT_UCSChar c = c1; c < c2; ++c)
 		    {
 			    FT_UInt glyph_idx = FT_Get_Char_Index(face, c);
