--- LibFoundation/Mathematics/Wm4ColorRGB.cpp.orig	Sun Mar 11 23:15:10 2007
+++ LibFoundation/Mathematics/Wm4ColorRGB.cpp	Wed Jul  4 18:32:14 2007
@@ -131,13 +131,13 @@
         fScalar*m_afTuple[2]);
 }
 //----------------------------------------------------------------------------
-ColorRGB Wm4::operator* (float fScalar, const ColorRGB& rkC)
+namespace Wm4 { ColorRGB operator* (float fScalar, const ColorRGB& rkC)
 {
     return ColorRGB(
         fScalar*rkC.m_afTuple[0],
         fScalar*rkC.m_afTuple[1],
         fScalar*rkC.m_afTuple[2]);
-}
+} }
 //----------------------------------------------------------------------------
 ColorRGB& ColorRGB::operator+= (const ColorRGB& rkC)
 {
