--- src/spriteset.cpp.orig	2006-03-27 10:27:53 UTC
+++ src/spriteset.cpp
@@ -618,3 +618,5 @@ void SpriteSet<T>::getSubdirConf( Settin
 }
 
 /**********************************************************/
+#include "sprite.hpp"
+template class SpriteSet<Sprite>;
