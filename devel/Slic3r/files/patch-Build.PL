--- Build.PL.orig	2017-11-27 10:42:25 UTC
+++ Build.PL
@@ -61,6 +61,7 @@ if ($ENV{SLIC3R_NO_AUTO}) {
     foreach my $module (sort keys %prereqs) {
         my $version = $prereqs{$module};
         next if eval "use $module $version; 1";
+        print $@;
         push @missing_prereqs, $module if exists $prereqs{$module};
         print "Missing prerequisite $module $version\n";
     }
