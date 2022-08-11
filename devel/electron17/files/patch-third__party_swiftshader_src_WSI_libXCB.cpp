--- third_party/swiftshader/src/WSI/libXCB.cpp.orig	2022-05-11 07:17:52 UTC
+++ third_party/swiftshader/src/WSI/libXCB.cpp
@@ -42,7 +42,7 @@ LibXcbExports *LibXCB::loadExports()
 			return LibXcbExports(RTLD_DEFAULT);
 		}
 
-		if(void *lib = loadLibrary("libxcb.so.1"))
+		if(void *lib = loadLibrary("libxcb.so"))
 		{
 			return LibXcbExports(lib);
 		}
