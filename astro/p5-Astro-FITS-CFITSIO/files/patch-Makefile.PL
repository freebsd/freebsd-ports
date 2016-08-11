--- Makefile.PL.orig	2012-01-19 19:18:45 UTC
+++ Makefile.PL
@@ -22,9 +22,9 @@ FOUND_IT: {
     }
   }
 
-  warn("CFITSIO environment variable not found, assuming /usr/local/cfitsio\n");
-  $inc = "-I/usr/local/cfitsio";
-  $libs = "-L/usr/local/cfitsio -lcfitsio -lm";
+  warn("CFITSIO environment variable not found, assuming /usr/local/include\n");
+  $inc = "-I/usr/local/include";
+  $libs = "-L/usr/local/include -lcfitsio -lm";
 
 }
 
