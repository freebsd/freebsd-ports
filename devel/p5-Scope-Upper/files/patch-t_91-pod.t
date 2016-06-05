--- t/91-pod.t.orig	2016-06-04 20:01:09 UTC
+++ t/91-pod.t
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
+load_or_skip_all('Test::Pod', '1.22', [ ]);
+
+all_pod_files_ok();
