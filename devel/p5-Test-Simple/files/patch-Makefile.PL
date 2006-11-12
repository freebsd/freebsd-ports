--- Makefile.PL.orig	Sat Nov 11 10:48:48 2006
+++ Makefile.PL	Sat Nov 11 10:49:03 2006
@@ -52,7 +52,7 @@
                         Test::Harness   => 2.03,
                        },
     # Added to the core somewhere around 5.7.2.
-    INSTALLDIRS     => $] >= 5.00702 ? 'perl' : 'site',
+    INSTALLDIRS     => 'site',
     ($ExtUtils::MakeMaker::VERSION <= 6.31 ? (LICENSE         => 'perl') : ()),
 );
 
