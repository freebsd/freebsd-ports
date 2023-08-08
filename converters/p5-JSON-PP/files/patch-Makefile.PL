--- Makefile.PL.orig	2022-12-30 04:30:47 UTC
+++ Makefile.PL
@@ -19,7 +19,7 @@ WriteMakefile(
               'Test::More'  => 0,
               'Scalar::Util' => '1.08'
     },
-    'EXE_FILES' => [ 'bin/json_pp' ],
+    'EXE_FILES' => [ 'bin/p5json_pp' ],
     'ABSTRACT_FROM' => 'lib/JSON/PP.pm', # retrieve abstract from module
     'AUTHOR'        => 'Makamaka Hannyaharamitu, E<lt>makamaka[at]cpan.orgE<gt>',
     ( $ExtUtils::MakeMaker::VERSION >= 6.3002 ? ('LICENSE' => 'perl', ) : () ),
