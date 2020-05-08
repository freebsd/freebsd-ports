--- Makefile.PL.orig	2019-02-18 16:03:19 UTC
+++ Makefile.PL
@@ -24,7 +24,7 @@ WriteMakefile(
               'Test::More'  => 0,
               %prereq,
     },
-    'EXE_FILES' => [ 'bin/json_pp' ],
+    'EXE_FILES' => [ 'bin/p5json_pp' ],
     ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
       (ABSTRACT_FROM => 'lib/JSON/PP.pm', # retrieve abstract from module
        AUTHOR     => 'Makamaka Hannyaharamitu, E<lt>makamaka[at]cpan.orgE<gt>') : ()),
