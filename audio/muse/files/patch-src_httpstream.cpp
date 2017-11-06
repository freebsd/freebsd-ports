--- src/httpstream.cpp.orig	2005-12-27 14:26:06 UTC
+++ src/httpstream.cpp
@@ -356,6 +356,7 @@ http_open( const char *url )
 {
     int sock = INVALID_SOCKET;
     FILE *fd = NULL;
+    const char *hp = NULL;
     char *host=NULL, *file=NULL, *p;
 	int port = 0;
 	
@@ -363,9 +364,8 @@ http_open( const char *url )
 	file = (char*)calloc( 1, strlen(url)+1 );
 	if (!host || !file) goto out;
 	
-	p = strstr(url, HTTP_PREFIX); if (!p) goto out;
-	p += 7;
-	strcpy(host, p);
+	hp = strstr(url, HTTP_PREFIX); if (!hp) goto out;
+	strcpy(host, hp + 7);
 	
 	p = strchr(host, '/');
 	if (p) {
