--- base/src/playlist.cpp.orig	2003-09-16 17:58:13 UTC
+++ base/src/playlist.cpp
@@ -1961,7 +1961,7 @@ Error PlaylistManager::ReadPlaylist(cons
     {
         // find a suitable plugin
         result = kError_FormatNotSupported;
-        char* extension = strrchr(url, '.');
+        const char* extension = strrchr(url, '.');
 
         if(extension)
         {
@@ -2042,7 +2042,7 @@ Error PlaylistManager::WritePlaylist(con
     {
         // find a suitable plugin
         result = kError_FormatNotSupported;
-        char* extension = strrchr(url, '.');
+        const char* extension = strrchr(url, '.');
 
         if(extension)
         {
