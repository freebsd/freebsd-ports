--- Makefile.PL.orig	Tue Apr  3 04:45:01 2001
+++ Makefile.PL	Tue Apr  3 04:45:07 2001
@@ -1,6 +1,6 @@
 use ExtUtils::MakeMaker;
 
-system('./Configure');
+system('./Configure -d');
 
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
