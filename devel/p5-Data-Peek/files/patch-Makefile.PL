--- Makefile.PL.orig	2018-02-26 15:08:16 UTC
+++ Makefile.PL
@@ -44,7 +44,7 @@ unless (exists $ENV{AUTOMATED_TESTING} a
 	    }
 	};
 
-    if ($dp_ok and prompt ("Do you want to install module DP as a shortcut for Data::Peek ?", "y") =~ m/[yY]/) {
+    if ($dp_ok) {
 	local $/;
 	open my $pm, "<", "Peek.pm" or die "Cannot read Peek.pm: $!\n";
 	my $vsn = do { <$pm> =~ m/^\$VERSION\s*=\s*"([0-9._]+)/m; $1 };
