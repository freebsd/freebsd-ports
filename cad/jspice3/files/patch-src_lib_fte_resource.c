--- src/lib/fte/resource.c.orig	Tue Nov 14 18:23:27 2006
+++ src/lib/fte/resource.c	Tue Nov 14 18:23:33 2006
@@ -36,7 +36,7 @@
 #endif
 #endif
 #endif 
-static char *enddata;
+char *enddata;
 static int origsec;
 static int origusec;
 static int lastsec;
