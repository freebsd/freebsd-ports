--- Makefile.PL.orig	Mon Feb 26 01:48:56 2001
+++ Makefile.PL	Mon Feb 26 01:49:03 2001
@@ -6,8 +6,6 @@
 WriteMakefile (
     NAME         => 'Term::ANSIColor',
     DISTNAME     => 'ANSIColor',
-    ($] >= 5.006 ?
-     (INSTALLDIRS => 'perl') : ()),
     ($] >= 5.005 ?
      (ABSTRACT   => 'Color output using ANSI escape sequences',
       AUTHOR     => 'Russ Allbery (rra@stanford.edu)') : ()),
