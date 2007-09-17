--- Makefile.PL.orig	2007-09-10 00:45:35.000000000 +0200
+++ Makefile.PL	2007-09-17 14:49:13.000000000 +0200
@@ -52,7 +52,7 @@
                         Test::Harness   => 2.03,
                        },
     # Added to the core in 5.7.3 and also 5.6.2.
-    INSTALLDIRS     => $] >= 5.006002 ? 'perl' : 'site',
+    INSTALLDIRS     => $] >= 'site',
     ($ExtUtils::MakeMaker::VERSION >= 6.31 ? (LICENSE         => 'perl') : ()),
 );
 
