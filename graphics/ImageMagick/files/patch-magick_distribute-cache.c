Index: magick/distribute-cache.c
===================================================================
--- magick/distribute-cache.c	(revision 17523)
+++ magick/distribute-cache.c	(working copy)
@@ -92,6 +92,10 @@
 #define SOCKET_TYPE SOCKET
 #define MAGICKCORE_HAVE_DISTRIBUTE_CACHE
 #else
+#define CLOSE_SOCKET(socket) 
+#define HANDLER_RETURN_TYPE  void *
+#define HANDLER_RETURN_VALUE  (void *) NULL
+#define SOCKET_TYPE  int
 #undef send
 #undef recv
 #define send(file,buffer,length,flags)  0
