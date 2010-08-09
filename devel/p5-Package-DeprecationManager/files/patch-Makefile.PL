--- Makefile.PL.orig	2010-08-05 15:45:40.707773492 +0200
+++ Makefile.PL	2010-08-05 15:45:51.844121268 +0200
@@ -12,9 +12,6 @@
   'ABSTRACT' => 'Manage deprecation warnings for your distribution',
   'AUTHOR' => 'Dave Rolsky <autarch@urth.org>',
   'BUILD_REQUIRES' => {
-    'Test::Exception' => '0',
-    'Test::More' => '0.88',
-    'Test::Warn' => '0'
   },
   'CONFIGURE_REQUIRES' => {
     'ExtUtils::MakeMaker' => '6.31'
