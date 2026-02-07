--- t/main_tests.t.orig	2016-06-20 14:43:13 UTC
+++ t/main_tests.t
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
