--- src/spriteset.cpp.orig	2006-03-27 14:27:53.000000000 +0400
+++ src/spriteset.cpp	2013-09-12 04:56:04.339229318 +0400
@@ -618,3 +618,5 @@
 }
 
 /**********************************************************/
+#include "sprite.hpp"
+template class SpriteSet<Sprite>;
