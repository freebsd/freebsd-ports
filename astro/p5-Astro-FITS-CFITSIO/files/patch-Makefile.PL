--- Makefile.PL.orig	2012-01-22 01:52:49.000000000 -0500
+++ Makefile.PL	2012-01-22 01:53:32.000000000 -0500
@@ -22,9 +22,9 @@
     }
   }
 
-  warn("CFITSIO environment variable not found, assuming /usr/local/cfitsio\n");
-  $inc = "-I/usr/local/cfitsio";
-  $libs = "-L/usr/local/cfitsio -lcfitsio -lm";
+  warn("CFITSIO environment variable not found, assuming /usr/local/include\n");
+  $inc = "-I/usr/local/include";
+  $libs = "-L/usr/local/include -lcfitsio -lm";
 
 }
 
