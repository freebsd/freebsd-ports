$FreeBSD$

--- misc.c.orig	Mon Oct 27 11:29:57 2003
+++ misc.c	Mon Oct 27 11:30:19 2003
@@ -90,8 +90,7 @@
     else
     {
       fprintf(stderr,"Usage: xtuner [-0x20 | -0x30]  -24 \n");
-      fprintf(stderr,"Which specifies the port for the radio card and 24hr
-      time format \n");
+      fprintf(stderr,"Which specifies the port for the radio card and 24hr time format \n");
       exit(1);
     }
     cmd++; 
