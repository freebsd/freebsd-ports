--- src/db/ConnectionPool.c.orig	Fri Jun  9 10:11:12 2006
+++ src/db/ConnectionPool.c	Fri Jun  9 10:11:19 2006
@@ -319,8 +319,9 @@
 
 static int fillPool(T P) {
 	int i;
-        P->error= NULL;
 	Connection_T con;
+
+        P->error= NULL;
 	for(i= 0; i < P->initialConnections; i++) {
 		if(! (con= Connection_new(P, &P->error))) {
                         if(i>0) {
