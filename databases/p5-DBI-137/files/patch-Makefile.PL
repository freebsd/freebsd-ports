--- Makefile.PL.orig	Sat Mar  1 02:50:24 2003
+++ Makefile.PL	Sun Mar  9 13:02:08 2003
@@ -23,7 +23,6 @@
 **************************************************************************
 };
     sleep 3;
-    my $pause = <>;
 }
 
 use ExtUtils::MakeMaker 5.16, qw(WriteMakefile $Verbose);
