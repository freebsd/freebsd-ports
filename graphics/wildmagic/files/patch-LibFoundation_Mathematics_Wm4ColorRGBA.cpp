--- LibFoundation/Mathematics/Wm4ColorRGBA.cpp.orig	Sun Mar 11 23:15:10 2007
+++ LibFoundation/Mathematics/Wm4ColorRGBA.cpp	Wed Jul  4 18:32:46 2007
@@ -142,14 +142,14 @@
         fScalar*m_afTuple[3]);
 }
 //----------------------------------------------------------------------------
-ColorRGBA Wm4::operator* (float fScalar, const ColorRGBA& rkC)
+namespace Wm4 { ColorRGBA operator* (float fScalar, const ColorRGBA& rkC)
 {
     return ColorRGBA(
         fScalar*rkC.m_afTuple[0],
         fScalar*rkC.m_afTuple[1],
         fScalar*rkC.m_afTuple[2],
         fScalar*rkC.m_afTuple[3]);
-}
+} }
 //----------------------------------------------------------------------------
 ColorRGBA& ColorRGBA::operator+= (const ColorRGBA& rkC)
 {
