--- lib/http/src/Http.cpp.orig	2003-09-16 17:35:09 UTC
+++ lib/http/src/Http.cpp
@@ -31,6 +31,7 @@ ________________________________________
 
 #include "config.h"
 #include <stdio.h> 
+#include <stdlib.h> 
 #include <sys/types.h>
 #include <sys/stat.h>
 #ifndef WIN32
@@ -39,6 +40,7 @@ ________________________________________
 #include <fcntl.h>    
 #include <errno.h>    
 #include <ctype.h>    
+#include <cstring>
 
 #ifdef WIN32
 #include <io.h>
@@ -768,7 +768,7 @@ int32_t Http::GetContentLengthFromHeader
 {
     int32_t result = -1;
 
-    char* cp = strstr(buffer, "Content-Length:");
+    const char* cp = strstr(buffer, "Content-Length:");
 
     if(cp)
     {
