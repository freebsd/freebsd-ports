--- ./memcache.c.orig	2009-02-22 16:01:43.000000000 +0000
+++ ./memcache.c	2010-09-15 23:28:08.037943831 +0000
@@ -642,7 +642,7 @@
 			}
 
 			if (deleted) {
-				pool->protocol->delete(request, request->key, request->key_len, value);
+				pool->protocol->delete(request, request->key, request->key_len, exptime);
 			}
 			else {
 				pool->protocol->mutate(request, *key, request->key, request->key_len, invert ? -value : value, defval, defval_used, exptime);
@@ -676,7 +676,7 @@
 		}
 
 		if (deleted) {
-			pool->protocol->delete(request, request->key, request->key_len, value);
+			pool->protocol->delete(request, request->key, request->key_len, exptime);
 		}
 		else {
 			pool->protocol->mutate(request, keys, request->key, request->key_len, invert ? -value : value, defval, defval_used, exptime);
