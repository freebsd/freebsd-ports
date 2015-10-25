--- sope-gdl1/PostgreSQL/PostgreSQL72Channel.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/PostgreSQL/PostgreSQL72Channel.m
@@ -203,7 +203,7 @@ static int openConnectionCount = 0;
   /* set client encoding */
 #if NG_SET_CLIENT_ENCODING
   if (![self->connection setClientEncoding:PGClientEncoding]) {
-    NSLog(@"WARNING: could not set client encoding to: '%s'", 
+    NSLog(@"WARNING: could not set client encoding to: '%@'", 
 	  PGClientEncoding);
   }
 #endif
