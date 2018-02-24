--- Makefile.PL.orig	2003-12-04 05:34:01 UTC
+++ Makefile.PL
@@ -8,6 +8,7 @@
 
 use ExtUtils::MakeMaker;
 
+=item
 # Ignore the following DBD Drivers
 
 %ignore = ('ExampleP' => 1,
@@ -215,7 +216,7 @@ print FH ");\n" ;
 
 close FH ;
     } 
-
+=cut
 
 WriteMakefile
     (
