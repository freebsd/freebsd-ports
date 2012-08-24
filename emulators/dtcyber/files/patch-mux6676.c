--- ./mux6676.c.orig	2012-08-24 13:31:54.621914000 +0200
+++ ./mux6676.c	2012-08-24 13:34:30.246915776 +0200
@@ -424,7 +424,11 @@
     if (listenFd < 0)
         {
         printf("Can't create socket\n");
+#if defined(_WIN32)
         return;
+#else
+        return (NULL);
+#endif
         }
 
     memset(&server, 0, sizeof(server));
@@ -435,13 +439,21 @@
     if (bind(listenFd, (struct sockaddr *)&server, sizeof(server)) < 0)
         {
         printf("Can't bind to socket\n");
+#if defined(_WIN32)
         return;
+#else
+        return (NULL);
+#endif
         }
 
     if (listen(listenFd, 5) < 0)
         {
         printf("Can't listen\n");
+#if defined(_WIN32)
         return;
+#else
+        return (NULL);
+#endif
         }
 
     while (1)
