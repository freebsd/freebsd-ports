--- src/error.c.orig	2016-05-03 08:56:24 UTC
+++ src/error.c
@@ -54,7 +54,7 @@ static void error_handler(int strflag, c
 	fflush(stderr);
 }
 
-int eioctl(int fd, int request, void *arg)
+int eioctl(int fd, unsigned long request, void *arg)
 {
 	int n;
 
