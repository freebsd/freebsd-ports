--- t/93-pod-spelling.t.orig	2016-06-04 20:01:09 UTC
+++ t/93-pod-spelling.t
@@ -0,0 +1,13 @@
+#!perl
+
+use strict;
+use warnings;
+
+use Test::More;
+
+use lib 't/lib';
+use VPIT::TestHelpers;
+
+load_or_skip_all('Test::Pod::Spelling::CommonMistakes', '1.0', [ ]);
+
+all_pod_files_ok();
