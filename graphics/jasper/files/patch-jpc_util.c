--- src/libjasper/jpc/jpc_util.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_util.c	2013-04-17 22:32:23.000000000 +0200
@@ -109,7 +109,7 @@
 	}
 
 	if (n) {
-		if (!(vs = jas_malloc(n * sizeof(double)))) {
+		if (!(vs = jas_malloc2(n, sizeof(double)))) {
 			return -1;
 		}
 
