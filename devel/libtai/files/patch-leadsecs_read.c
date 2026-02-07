--- leapsecs_read.c.orig	Fri Jun 16 22:44:31 2000 UTC
+++ leapsecs_read.c
@@ -18,7 +18,7 @@
   int i;
   struct tai u;
 
-  fd = open("/etc/leapsecs.dat",O_RDONLY | O_NDELAY);
+  fd = open("%%PREFIX%%/etc/leapsecs.dat",O_RDONLY | O_NDELAY);
   if (fd == -1) {
     if (errno != ENOENT) return -1;
     if (leapsecs) free(leapsecs);
