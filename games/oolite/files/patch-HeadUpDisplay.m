--- src/Core/HeadUpDisplay.m.orig	2006-07-18 19:34:21.000000000 +0200
+++ src/Core/HeadUpDisplay.m	2012-01-14 07:01:40.000000000 +0100
@@ -48,6 +48,8 @@
 #import "TextureStore.h"
 #import "OOTrumble.h"
 
+#include <assert.h>
+
 static const char *toAscii(unsigned inCodePoint);
 
 @implementation HeadUpDisplay
