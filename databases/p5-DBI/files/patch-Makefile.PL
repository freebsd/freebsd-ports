--- Makefile.PL.orig	Tue Oct  5 23:06:32 2004
+++ Makefile.PL	Fri Oct 15 12:35:43 2004
@@ -25,7 +25,6 @@
 **************************************************************************
 };
     sleep 3;
-    my $pause = <>;
 }
 
 use ExtUtils::MakeMaker 5.16, qw(WriteMakefile $Verbose);
@@ -34,9 +33,6 @@
 use File::Find;
 use File::Spec;
 use strict;
-
-use Test::Harness;	# tests use it so check it's loadable early
-use Test::More 0.4;	# tests use it so check it's loadable early
 
 use DBI::DBD;
 
