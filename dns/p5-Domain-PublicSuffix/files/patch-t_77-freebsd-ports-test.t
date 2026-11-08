--- t/77-freebsd-ports-test.t.orig	1970-01-01 00:00:00 UTC
+++ t/77-freebsd-ports-test.t
@@ -0,0 +1,33 @@
+#!/usr/bin/env perl
+
+# Conduct tests to address issues specific to the port:
+#
+# - Fix mismatches in relative file paths within the test target
+#   directory ($WRKSRC) used by 'make test', and apply the fixes to the
+#   existing tests.
+#
+# - Verify that the port does not reference the latest list.
+#
+#   - Compare the latest list with the built-in list.
+#
+#   - Detect unintended use of the latest list by testing a suffix such as
+#     zabc.net, an entry in the latest list that is not present in the
+#     built-in list.
+#
+#[notes]
+# the latest list:   installed public suffix list
+# the built-in list: default or embedded public suffix list
+
+use strict;
+use warnings;
+use Test::More;
+use Domain::PublicSuffix;
+
+my $ps = Domain::PublicSuffix->new({
+    'dataFile' => 't/effective_tld_names.dat'
+});
+   $ps->get_root_domain('zabc.net');
+
+is($ps->suffix, 'net', 'default ok');
+
+done_testing();
