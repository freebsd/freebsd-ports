# Bug 1235395 - whine.pl broken due to a missing generate_email() routine
# https://bugzilla.mozilla.org/show_bug.cgi?id=1235395
# Status: Upstreamed, pending next release

--- whine.pl.orig	2015-12-22 21:22:11 UTC
+++ whine.pl
@@ -13,14 +13,13 @@
 use 5.10.1;
 use strict;
 use warnings;
-
 use lib qw(. lib);
 
 use Bugzilla;
 use Bugzilla::Constants;
 use Bugzilla::Search;
 use Bugzilla::User;
-use Bugzilla::Mailer;
+use Bugzilla::Mailer qw(MessageToMTA generate_email);
 use Bugzilla::Util;
 use Bugzilla::Group;
 
