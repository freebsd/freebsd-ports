--- Makefile.PL.orig	2011-07-21 05:19:47.000000000 +0800
+++ Makefile.PL	2011-10-10 23:25:49.212106596 +0800
@@ -5,8 +5,6 @@
 WriteMakefile (
     NAME          => 'Term::ANSIColor',
     DISTNAME      => 'Term-ANSIColor',
-    ($] >= 5.006 ?
-     (INSTALLDIRS => 'perl') : ()),
     ($] >= 5.005 ?
      (ABSTRACT    => 'Color output using ANSI escape sequences',
       AUTHOR      => 'Russ Allbery (rra@stanford.edu)') : ()),
