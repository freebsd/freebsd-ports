--- src/filetypes/povray/SavePov.c.orig	Fri Aug  9 18:17:09 2002
+++ src/filetypes/povray/SavePov.c	Tue Oct 26 17:04:03 2004
@@ -799,6 +799,7 @@
 
     default:
       /* panic */
+      ;
   }
   fprintf(OutFile, "  location <%g, %g, %g>\n", Camera->Location[0],
                                                 Camera->Location[1],
