--- t/95-portability-files.t.orig	2016-06-04 20:01:09 UTC
+++ t/95-portability-files.t
@@ -0,0 +1,13 @@
+#!perl -T
+
+use strict;
+use warnings;
+
+use Test::More;
+
+use lib 't/lib';
+use VPIT::TestHelpers;
+
+load_or_skip_all('Test::Portability::Files', undef, [ ]);
+
+run_tests();
