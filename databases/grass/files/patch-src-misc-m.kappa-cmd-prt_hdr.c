--- src/misc/m.kappa/cmd/prt_hdr.c.orig	Sun Jul 11 17:16:19 2004
+++ src/misc/m.kappa/cmd/prt_hdr.c	Sun Jul 11 17:16:32 2004
@@ -10,7 +10,7 @@
     if ((fd = fopen(output, "w")) == NULL) {
       fprintf (stderr,
 	"ERROR: can't open <%s> to write header information\n", output);
-      exit();
+      exit(1);
     }
 
   fprintf (fd, "\n\t\t%s\n", title);
