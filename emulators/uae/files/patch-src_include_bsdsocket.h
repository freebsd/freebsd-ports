--- src/include/bsdsocket.h.orig	2025-05-05 16:22:22 UTC
+++ src/include/bsdsocket.h
@@ -29,7 +29,7 @@ extern void deinit_socket_layer (void);
 #define MAXADDRLEN 256
 
 /* allocated and maintained on a per-task basis */
-struct socketbase {
+extern struct socketbase {
     struct socketbase *next;
     struct socketbase *nextsig;	/* queue for tasks to signal */
 
