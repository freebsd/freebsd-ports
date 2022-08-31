--- Makefile.PL.orig	2022-06-24 16:40:06 UTC
+++ Makefile.PL
@@ -1,7 +1,7 @@
 use strict;
 use warnings;
 
-use Alien::Base::Wrapper 'WriteMakefile';
+use ExtUtils::MakeMaker;

 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
