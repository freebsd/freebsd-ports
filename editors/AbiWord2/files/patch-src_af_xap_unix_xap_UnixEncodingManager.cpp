--- src/af/xap/unix/xap_UnixEncodingManager.cpp.orig	Fri Mar  7 02:33:39 2003
+++ src/af/xap/unix/xap_UnixEncodingManager.cpp	Tue Mar 25 19:49:09 2003
@@ -475,6 +475,7 @@
 	NativeUnicodeEncodingName = "UTF-8";
 	LanguageISOName = "en";
 	LanguageISOTerritory = "US";   
+	XAP_EncodingManager::initialize();
 
 	if (!*locname || !strcmp(locname,"C"))
 	{ 	/* paranoic case - broken system */
@@ -582,6 +583,5 @@
 			FREEP(mod);
 		}
 	}
-	XAP_EncodingManager::initialize();
 	describe();
 };
