--- src/unix_processes.c.orig	2009-07-03 09:58:53.000000000 +0300
+++ src/unix_processes.c	2009-07-03 09:58:59.000000000 +0300
@@ -473,6 +473,7 @@
 {
 #if defined(HAVE_PTYS)
     int master;
+    char c;
 
 # if defined(HAVE_DEV_PTMX) && defined(HAVE_GRANTPT)
     master = open("/dev/ptmx", O_RDWR);
