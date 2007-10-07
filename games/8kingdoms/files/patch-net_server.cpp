--- net/server.cpp	2007-10-07 03:21:11.000000000 -0500
+++ net/server.cpp	2007-10-07 03:21:57.000000000 -0500
@@ -415,7 +415,7 @@
   #ifdef WIN32 
     int sin_size = sizeof(struct sockaddr_in); // Windows chteji do accept int
   #else
-    size_t sin_size = sizeof(struct sockaddr_in);
+    socklen_t sin_size = sizeof(struct sockaddr_in);
   #endif
 
     int s;
