--- Source/FreeImage/PluginPSD.cpp.orig	2018-09-04 20:32:27 UTC
+++ Source/FreeImage/PluginPSD.cpp
@@ -127,7 +127,7 @@ Load(FreeImageIO *io, fi_handle handle, int page, int 
 static BOOL DLL_CALLCONV
 Save(FreeImageIO *io, FIBITMAP *dib, fi_handle handle, int page, int flags, void *data) {
 	if(!handle) {
-		return NULL;
+	//return NULL;
 	}
 	try {
 		psdParser parser;
