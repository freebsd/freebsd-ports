$FreeBSD$

--- ../src/share/native/sun/awt/font/fontmanager/fontobjects/t2kScalerContext.cpp	12 Jul 2001 21:54:30 -0000	1.2
+++ ../src/share/native/sun/awt/font/fontmanager/fontobjects/t2kScalerContext.cpp	10 Aug 2004 14:29:24 -0000
@@ -784,7 +784,7 @@
 CMAPMapper::CharsToGlyphs(
         int count, const Unicode unicodes[], UInt32 glyphs[]) const
 {
-    ConvertUnicodeToGlyphs(*font, (unsigned char *)cmap, count, unicodes, glyphs);
+    ConvertUnicodeToGlyphs(*font, (byte*&)cmap, count, unicodes, glyphs);
 }
 
 //////////////////////////////////////////////////////////////////////////////
