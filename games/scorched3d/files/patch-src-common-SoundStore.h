--- src/common/SoundStore.h.orig	Wed Jul 30 17:41:28 2003
+++ src/common/SoundStore.h	Sun Aug  3 09:07:12 2003
@@ -29,7 +29,7 @@
 #include <string>
 
 #define CACHE_SOUND(var, filename) 										\
-		static SoundBuffer* ##var = SoundStore::instance()->fetchOrCreateBuffer(##filename);
+		static SoundBuffer* var = SoundStore::instance()->fetchOrCreateBuffer(filename);
 
 class SoundStore
 {
