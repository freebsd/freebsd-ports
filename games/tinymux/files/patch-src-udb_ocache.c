--- udb_ocache.c.orig	Tue Oct 28 01:02:12 2003
+++ udb_ocache.c	Tue Oct 28 01:02:25 2003
@@ -32,7 +32,7 @@
 #endif
 
 extern struct Obj *dddb_get();
-extern void logf();
+extern void Logf();
 
 /*
  * This is by far the most complex and kinky code in UnterMUD. You should
@@ -220,7 +220,7 @@
 
 	sp = sys_c = (CacheLst *) malloc((unsigned)cwidth * sizeof(CacheLst));
 	if (sys_c == (CacheLst *) 0) {
-		logf(ncmsg, (char *)-1, "\n", (char *)0);
+		Logf(ncmsg, (char *)-1, "\n", (char *)0);
 		return (-1);
 	}
 	/*
@@ -228,7 +228,7 @@
 	 */
 	cp = (Cache *) malloc(cwidth * cdepth * sizeof(Cache));
 	if (cp == (Cache *) 0) {
-		logf(ncmsg, (char *)-1, "\n", (char *)0);
+		Logf(ncmsg, (char *)-1, "\n", (char *)0);
 		return (-1);
 	}
 	for (x = 0; x < cwidth; x++, sp++) {
@@ -358,7 +358,7 @@
 	 */
 	if (nam == (Aname *) 0 || !cache_initted) {
 #ifdef	CACHE_VERBOSE
-		logf("cache_get: NULL object name - programmer error\n", (char *)0);
+		Logf("cache_get: NULL object name - programmer error\n", (char *)0);
 #endif
 		return ((Attr *) 0);
 	}
@@ -548,7 +548,7 @@
 	 */
 	if (obj == (Attr *) 0 || nam == (Aname *) 0 || !cache_initted) {
 #ifdef	CACHE_VERBOSE
-		logf("cache_put: NULL object/name - programmer error\n", (char *)0);
+		Logf("cache_put: NULL object/name - programmer error\n", (char *)0);
 #endif
 		return (1);
 	}
