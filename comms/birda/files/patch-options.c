--- src/options.c.orig	Wed Jan  2 17:22:11 2002
+++ src/options.c	Thu Aug 28 17:17:00 2003
@@ -427,6 +427,8 @@
     exit(-2);
   }
 
+  setbuf(stdin, 0);
+  setbuf(stdout, 0);
   if(pty && !openPty(pty)) {
     log("Cannot open pty\n");
     exit(-6);
