--- 3d-viewer/3d_cache/3d_cache.cpp.orig	2022-05-06 18:57:13 +0200
+++ 3d-viewer/3d_cache/3d_cache.cpp
@@ -199,7 +199,8 @@
     FlushCache();
 
     // We'll delete ".3dc" cache files older than this many days
-    int clearCacheInterval = commonSettings->m_System.clear_3d_cache_interval;
+    int clearCacheInterval = 0;
+    if(commonSettings) clearCacheInterval = commonSettings->m_System.clear_3d_cache_interval;
 
     // An interval of zero means the user doesn't want to ever clear the cache
 
