--- Makefile.PL.orig	2011-01-05 10:36:07.000000000 +0800
+++ Makefile.PL	2011-01-05 10:36:27.000000000 +0800
@@ -8,8 +8,8 @@
 }
 else {
   warn("CFITSIO environment variable not found, assuming /usr/local/cfitsio\n");
-  $inc = "-I/usr/local/cfitsio";
-  $libs = "-L/usr/local/cfitsio -lcfitsio -lm";
+  $inc = "-I/usr/local/include";
+  $libs = "-L/usr/local/lib -lcfitsio -lm";
 }
 
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
