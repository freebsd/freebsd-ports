--- Makefile.PL.orig	2020-07-13 09:43:02 UTC
+++ Makefile.PL
@@ -46,8 +46,6 @@ WriteMakefile(
 
     INSTALLDIRS => ($] >= 5.009 && $] < 5.011 ? 'perl' : 'site'),
 
-    EXE_FILES => ['bin/zipdetails', 'bin/streamzip'],
-
     (
     $] >= 5.009 && $] <= 5.011001 && ! $ENV{PERL_CORE}
         ? (INSTALLPRIVLIB    => '$(INSTALLARCHLIB)')
