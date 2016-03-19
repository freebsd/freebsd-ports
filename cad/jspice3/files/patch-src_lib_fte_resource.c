--- src/lib/fte/resource.c.orig	1997-03-21 22:03:41 UTC
+++ src/lib/fte/resource.c
@@ -36,7 +36,7 @@ static struct timeb lasttime;
 #endif
 #endif
 #endif 
-static char *enddata;
+char *enddata;
 static int origsec;
 static int origusec;
 static int lastsec;
