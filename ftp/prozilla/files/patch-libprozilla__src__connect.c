--- ./libprozilla/src/connect.c.orig	Wed Feb  8 14:19:54 2006
+++ ./libprozilla/src/connect.c	Sun Sep 17 14:00:02 2006
@@ -54,16 +54,14 @@
   hints.ai_socktype = SOCK_STREAM;
 
     error = getaddrinfo(name, szPort, &hints, &res);
-    if (error) {
-           freeaddrinfo(res);
-            return HOSTERR;
-        }
+    if (error)
+      return HOSTERR;
 
 
   /* Create a socket. */
   if ((*sock = socket(res->ai_family, res->ai_socktype, IPPROTO_TCP)) < 1)
   {
-    free(res);
+    freeaddrinfo(res);
     return CONSOCKERR;
   }
 
@@ -110,11 +108,11 @@
 
     if (errno == ECONNREFUSED)
     {
-      free(res);
+      freeaddrinfo(res);
       return CONREFUSED;
     } else
     {
-      free(res);
+      freeaddrinfo(res);
       return CONERROR;
     }
   } else
@@ -133,7 +131,7 @@
     setsockopt(*sock, SOL_SOCKET, SO_KEEPALIVE,
                (char *) &opt, (int) sizeof(opt));  
  
-  free(res);
+  freeaddrinfo(res);
 
   return NOCONERROR;
 }
