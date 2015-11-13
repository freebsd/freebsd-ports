--- t/main_tests.t.orig	2015-10-16 16:34:06.906634577 +0200
+++ t/main_tests.t	2015-10-16 16:34:56.598631573 +0200
@@ -3,7 +3,10 @@
 use Test::More;
 use strict;
 use warnings;
-use rlib '../lib', './lib';
+#use rlib '../lib', './lib';
+use FindBin;
+use lib "$FindBin::Bin/lib";
+use lib "$FindBin::Bin/../lib";
 
 use Geo::ShapeFile;
 use Geo::ShapeFile::Shape;
