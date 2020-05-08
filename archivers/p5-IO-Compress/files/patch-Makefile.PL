--- Makefile.PL.orig	2019-12-07 14:59:48 UTC
+++ Makefile.PL
@@ -42,7 +42,6 @@ WriteMakefile( 
 
     INSTALLDIRS => ($] >= 5.009 && $] < 5.011 ? 'perl' : 'site'),
 
-    EXE_FILES => ['bin/zipdetails', 'bin/streamzip'],
     
     (
     $] >= 5.009 && $] <= 5.011001 && ! $ENV{PERL_CORE}
