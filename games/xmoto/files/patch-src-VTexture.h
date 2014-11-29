--- src/VTexture.h.orig	2011-10-12 00:18:35.000000000 +0400
+++ src/VTexture.h	2014-11-24 22:08:42.749026473 +0300
@@ -135,7 +135,7 @@
 
   void cleanUnregistredTextures();
 
-  HashNamespace::hash_map<const char*, int*, HashNamespace::hash<const char*>, hashcmp_str> m_textureSizeCache;
+  HashNamespace::hash_map<std::string, int*> m_textureSizeCache;
   std::vector<std::string> m_textureSizeCacheKeys;
   std::vector<int*> m_textureSizeCacheValues;
 
