# Bug 1235395 - whine.pl broken due to a missing generate_email() routine
# https://bugzilla.mozilla.org/show_bug.cgi?id=1235395
# Status: Upstreamed, pending next release

--- whine.pl.orig	2024-09-03 14:36:48 UTC
+++ whine.pl
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -T
+#!/usr/local/bin/perl -T
 # This Source Code Form is subject to the terms of the Mozilla Public
 # License, v. 2.0. If a copy of the MPL was not distributed with this
 # file, You can obtain one at http://mozilla.org/MPL/2.0/.
@@ -13,14 +13,13 @@ use warnings;
 use 5.14.0;
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
 
