$FreeBSD$

--- ../../j2se/src/share/native/sun/awt/font/fontmanager/fontobjects/t2kScalerContext.cpp.orig	Fri Jul 30 18:00:09 2004
+++ ../../j2se/src/share/native/sun/awt/font/fontmanager/fontobjects/t2kScalerContext.cpp	Fri Jul 30 22:11:36 2004
@@ -937,14 +937,14 @@
 CMAPMapper::CharsToGlyphs(
     int count, const Unicode16 unicodes[], UInt32 glyphs[]) const
 {
-    ConvertUnicodeToGlyphs(*font, (unsigned char *)cmap, count, unicodes, glyphs);
+    ConvertUnicodeToGlyphs(*font, (byte*&)cmap, count, unicodes, glyphs);
 }
 
 void
 CMAPMapper::CharsToGlyphs(
         int count, const Unicode32 unicodes[], UInt32 glyphs[]) const
 {
-    ConvertUnicodeToGlyphs(*font, (unsigned char *)cmap, count, unicodes, glyphs);
+    ConvertUnicodeToGlyphs(*font, (byte*&)cmap, count, unicodes, glyphs);
 }
 
 //////////////////////////////////////////////////////////////////////////////
