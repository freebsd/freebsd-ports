--- Makefile.PL~	Mon Aug 26 06:53:00 2002
+++ Makefile.PL	Wed Aug 28 11:15:58 2002
@@ -37,7 +37,7 @@
                         File::Spec      => 0.6,
                        },
     # Added to the core somewhere around 5.7.2.
-    INSTALLDIRS     => $] >= 5.00702 ? 'perl' : 'site'
+    INSTALLDIRS     => 'site'
 );
 
 
