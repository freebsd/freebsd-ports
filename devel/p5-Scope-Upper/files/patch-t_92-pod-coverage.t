--- t/92-pod-coverage.t.orig	2016-06-04 20:01:09 UTC
+++ t/92-pod-coverage.t
@@ -0,0 +1,14 @@
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
+load_or_skip_all('Test::Pod::Coverage', '1.08', [ ]);
+load_or_skip_all('Pod::Coverage',       '0.18'     );
+
+all_pod_coverage_ok( { also_private => [ qr/^_/, qr/^CLONE(_SKIP)?$/ ] } );
