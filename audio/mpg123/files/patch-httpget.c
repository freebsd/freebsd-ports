--- httpget.c.orig	Fri Nov  5 16:11:04 2004
+++ httpget.c	Fri Nov  5 16:43:27 2004
@@ -55,11 +55,10 @@
 #endif
 	int pos = 0;
 
-	while(1) {
+	while(pos < maxlen) {
 		if( read(fileno(f),string+pos,1) == 1) {
 			pos++;
 			if(string[pos-1] == '\n') {
-				string[pos] = 0;
 				break;
 			}
 		}
@@ -68,6 +67,7 @@
 			exit(1);
 		}
 	}
+	string[pos] = 0;
 #if 0
 	do {
 		result = fgets(string, maxlen, f);
@@ -114,6 +114,7 @@
 int getauthfromURL(char *url,char *auth)
 {
   char *pos;
+  int len;
 
   *auth = 0;
 
@@ -126,8 +127,14 @@
       if( url[i] == '/' )
          return 0;
     }
-    strncpy(auth,url,pos-url);
-    auth[pos-url] = 0;
+
+    if ((pos-url) > 255)
+      len = 255;
+    else
+      len = pos-url;
+
+    strncpy(auth,url,len);
+    auth[len] = 0;
     strcpy(url,pos+1);
     return 1;
   }
@@ -292,11 +299,11 @@
 			}
 			strcat (request, sptr);
 		}
-		sprintf (request + strlen(request),
+		snprintf (request + strlen(request), linelength - strlen(request),
 			" HTTP/1.0\r\nUser-Agent: %s/%s\r\n",
 			prgName, prgVersion);
 		if (host) {
-			sprintf(request + strlen(request),
+			snprintf(request + strlen(request), linelength - strlen(request),
 				"Host: %s:%s\r\n", host, myport);
 #if 0
 			free (host);
