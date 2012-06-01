--- src/impex/png.cxx.orig	2010-12-03 18:40:34.000000000 +0100
+++ src/impex/png.cxx	2012-05-05 07:53:39.000000000 +0200
@@ -320,7 +320,7 @@
 #if (PNG_LIBPNG_VER > 10008) && defined(PNG_READ_iCCP_SUPPORTED)
         char * dummyName;
         int dummyCompType;
-        char * profilePtr;
+        png_byte * profilePtr;
         png_uint_32 profileLen;
         if (png_get_valid( png, info, PNG_INFO_iCCP )) {
             png_get_iCCP(png, info, &dummyName, &dummyCompType, &profilePtr, &profileLen) ;
@@ -592,7 +592,7 @@
         // set icc profile
         if (iccProfile.size() > 0) {
             png_set_iCCP(png, info, (png_charp)("icc"), 0,
-                         (png_charp)iccProfile.begin(), (png_uint_32)iccProfile.size());
+                         (const png_byte *)iccProfile.begin(), (png_uint_32)iccProfile.size());
         }
 #endif
 
