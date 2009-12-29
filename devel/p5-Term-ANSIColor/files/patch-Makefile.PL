--- ./Makefile.PL.orig	2009-12-15 05:07:34.733778581 +0000
+++ ./Makefile.PL	2009-12-15 05:07:42.485119095 +0000
@@ -5,8 +5,6 @@
 WriteMakefile (
     NAME          => 'Term::ANSIColor',
     DISTNAME      => 'ANSIColor',
-    ($] >= 5.006 ?
-     (INSTALLDIRS => 'perl') : ()),
     ($] >= 5.005 ?
      (ABSTRACT    => 'Color output using ANSI escape sequences',
       AUTHOR      => 'Russ Allbery (rra@stanford.edu)') : ()),
