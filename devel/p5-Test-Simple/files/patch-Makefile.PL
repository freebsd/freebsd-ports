--- Makefile.PL.orig	Wed Mar 14 08:25:01 2007
+++ Makefile.PL	Fri Mar 16 10:22:12 2007
@@ -52,7 +52,7 @@
                         Test::Harness   => 2.03,
                        },
     # Added to the core in 5.7.3 and also 5.6.2.
-    INSTALLDIRS     => $] >= 5.006002 ? 'perl' : 'site',
+    INSTALLDIRS     => 'site',
     ($ExtUtils::MakeMaker::VERSION <= 6.31 ? (LICENSE         => 'perl') : ()),
 );
 
