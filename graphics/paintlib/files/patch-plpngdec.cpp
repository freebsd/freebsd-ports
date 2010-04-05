--- common/plpngdec.cpp.orig	2004-10-03 19:49:22.000000000 +0200
+++ common/plpngdec.cpp	2010-04-05 21:15:31.000000000 +0200
@@ -108,7 +108,7 @@
 
   SetBmpInfo (PLPoint (width, height), PLPoint(0,0), pf);
 
-  PLULONG XRes, YRes;
+  png_uint_32 XRes, YRes;
   int UnitType;
   png_get_pHYs (m_png_ptr, m_info_ptr, &XRes, &YRes,
                 &UnitType);
