--- Makefile.PL.orig	2025-08-13 12:44:53 UTC
+++ Makefile.PL
@@ -25,7 +25,6 @@ WriteMakefile
         'List::Util' => 0,
         'version' => 0.88,
     },
-    'EXE_FILES' => [ _scripts() ],
     'PL_FILES' => {},
     LICENSE => 'perl',
     @extra,
