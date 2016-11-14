--- src/VTexture.h.orig	2011-10-11 20:18:35 UTC
+++ src/VTexture.h
@@ -135,7 +135,7 @@ private:
 
   void cleanUnregistredTextures();
 
-  HashNamespace::hash_map<const char*, int*, HashNamespace::hash<const char*>, hashcmp_str> m_textureSizeCache;
+  HashNamespace::hash_map<std::string, int*> m_textureSizeCache;
   std::vector<std::string> m_textureSizeCacheKeys;
   std::vector<int*> m_textureSizeCacheValues;
 
