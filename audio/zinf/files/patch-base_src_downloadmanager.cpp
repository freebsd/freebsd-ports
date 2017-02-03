--- base/src/downloadmanager.cpp.orig	2003-09-16 17:34:53 UTC
+++ base/src/downloadmanager.cpp
@@ -398,7 +398,7 @@ Error DownloadManager::ReadDownloadFile(
     {
         // find a suitable plugin
         result = kError_FormatNotSupported;
-        char* extension = strrchr(url, '.');
+        const char* extension = strrchr(url, '.');
 
         if(extension)
         {
@@ -558,7 +558,7 @@ static int32_t GetContentLengthFromHeade
 {
     int32_t result = -1;
 
-    char* cp = strstr(buffer, "Content-Length:");
+    const char* cp = strstr(buffer, "Content-Length:");
 
     if(cp)
     {
@@ -572,7 +572,7 @@ static int32_t GetContentLengthFromHeade
 
 static void GetContentTimeFromHeader(const char* buffer, string &mTime)
 {
-    char* cp = strstr(buffer, "Last-Modified:");
+    const char* cp = strstr(buffer, "Last-Modified:");
     if(cp)
     {
         string::size_type pos;
@@ -748,7 +748,7 @@ Error DownloadManager::Download(Download
         struct sockaddr_in  addr;
         struct hostent      host;
         SOCKET s = -1;
-        char* file = NULL;
+        const char* file = NULL;
         bool useProxy;
         struct stat st;
 	string destPath;
