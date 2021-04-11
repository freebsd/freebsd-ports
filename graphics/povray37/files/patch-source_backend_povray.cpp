--- source/backend/povray.cpp.orig	2018-05-27 09:54:06 UTC
+++ source/backend/povray.cpp
@@ -68,7 +68,7 @@
 		extern "C" const char* TIFFGetVersion(void);
 	#endif
     #ifndef OPENEXR_MISSING
-        #include <IlmBaseConfig.h>
+        #include <ImathConfig.h>
         #include <OpenEXRConfig.h>
         // NOTE:
         //  Versions of OpenEXR and IlmImf prior to 1.7.1 do not seem to have a way to get the version number,
