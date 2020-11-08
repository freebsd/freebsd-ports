--- Makefile.PL.orig	2020-06-08 18:59:47 UTC
+++ Makefile.PL
@@ -25,7 +25,6 @@ WriteMakefile
         'List::Util' => 0,
         'version' => 0.88,
     },
-    'EXE_FILES' => [ _scripts() ],
     'INSTALLDIRS' => ($] < 5.011 ? 'perl' : 'site'),
     'PL_FILES' => {},
     LICENSE => 'perl',
