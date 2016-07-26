--- src/wrapper/common.hpp.orig	2008-04-24 19:44:50 UTC
+++ src/wrapper/common.hpp
@@ -50,10 +50,7 @@ using namespace std;
 
 
 
-#define TAGPY_TAGLIB_HEX_VERSION \
-  (TAGLIB_MAJOR_VERSION << 16) + \
-  (TAGLIB_MINOR_VERSION << 8) + \
-  (TAGLIB_PATCH_VERSION << 0)
+#define TAGPY_TAGLIB_HEX_VERSION 0x10800
 
 #if (TAGPY_TAGLIB_HEX_VERSION < 0x10400)
 #warning !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
