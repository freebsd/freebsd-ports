--- Makefile.PL.orig	Thu Sep  9 21:26:15 2004
+++ Makefile.PL	Thu Sep 16 14:49:44 2004
@@ -24,10 +24,10 @@
         recommends  ('Module::ScanDeps' => 0.28),
         recommends  ('Module::CoreList'),
     ],
-    'Bundle other CPAN packages' => [
-        -default            => 0,
-        recommends  ('CPANPLUS' => 0.040),
-    ],
+#    'Bundle other CPAN packages' => [
+#        -default            => 0,
+#        recommends  ('CPANPLUS' => 0.040),
+#    ],
     'PAR-based binary distributions' => [
         -default            => 0,
         recommends  ('PAR::Dist' => 0.03),
