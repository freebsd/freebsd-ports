--- cpan/podlators/t/devise-date.t.orig	2015-04-15 07:47:18 UTC
+++ cpan/podlators/t/devise-date.t
@@ -1,15 +1,28 @@
-#!/usr/bin/perl -w
-
-# In order for MakeMaker to build in the core, nothing can use
-# Fcntl which includes POSIX.  devise_date()'s use of strftime()
-# was replaced.  This tests that it's identical.
+#!/usr/bin/perl
+#
+# In order for MakeMaker to build in the core, nothing can use Fcntl which
+# includes POSIX.  devise_date()'s use of strftime() was replaced.  This tests
+# that it's identical.  It also tests special handling of the POD_MAN_DATE
+# environment variable.
 
+use 5.006;
 use strict;
-
-use Test::More tests => 1;
+use warnings;
 
 use Pod::Man;
 use POSIX qw(strftime);
 
+use Test::More tests => 2;
+
+# Check that the results of device_date matches strftime.  There is no input
+# file name, so this will use the current time.
 my $parser = Pod::Man->new;
-is $parser->devise_date, strftime("%Y-%m-%d", localtime);
+is(
+    $parser->devise_date,
+    strftime('%Y-%m-%d', localtime()),
+    'devise_date matches strftime'
+);
+
+# Set the override environment variable and ensure that it's honored.
+local $ENV{POD_MAN_DATE} = '2014-01-01';
+is($parser->devise_date, '2014-01-01', 'devise_date honors POD_MAN_DATE');
