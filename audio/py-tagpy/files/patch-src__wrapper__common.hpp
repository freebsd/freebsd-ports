--- ./src/wrapper/common.hpp.orig	2013-03-22 10:46:55.000000000 +0100
+++ ./src/wrapper/common.hpp	2013-03-22 10:47:04.000000000 +0100
@@ -50,10 +50,7 @@
 
 
 
-#define TAGPY_TAGLIB_HEX_VERSION \
-  (TAGLIB_MAJOR_VERSION << 16) + \
-  (TAGLIB_MINOR_VERSION << 8) + \
-  (TAGLIB_PATCH_VERSION << 0)
+#define TAGPY_TAGLIB_HEX_VERSION 0x10800
 
 #if (TAGPY_TAGLIB_HEX_VERSION < 0x10400)
 #warning !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
