--- ./Bugzilla/Install/Requirements.pm.orig	2011-08-05 04:25:35.000000000 +0200
+++ ./Bugzilla/Install/Requirements.pm	2011-08-16 08:55:28.000000000 +0200
@@ -698,8 +698,9 @@
     # show "ok" or "not found".
     if (exists $params->{found}) {
         my $found_string;
-        # We do a string compare in case it's non-numeric.
-        if ($found and $found eq "-1") {
+        # We do a string compare in case it's non-numeric. We make sure
+        # it's not a version object as negative versions are forbidden.
+        if ($found && !ref($found) && $found eq '-1') {
             $found_string = install_string('module_not_found');
         }
         elsif ($found) {
