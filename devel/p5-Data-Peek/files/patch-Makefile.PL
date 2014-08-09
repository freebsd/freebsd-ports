--- ./Makefile.PL.orig	2014-01-01 12:53:34.000000000 +0100
+++ ./Makefile.PL	2014-08-09 13:50:03.000000000 +0200
@@ -33,9 +33,9 @@
 $ExtUtils::MakeMaker::VERSION > 6.30 and $wm{LICENSE} = "perl";
 
 unless (exists $ENV{AUTOMATED_TESTING} and $ENV{AUTOMATED_TESTING} == 1) {
-    if (prompt ("Do you want to install module DP as a shortcut for Data::Peek ?", "y") =~ m/[yY]/) {
+    {
 	local $/;
-	open my $pm, "<", "Peek.pm" or die "CAnnot read Peek.pm: $!\n";
+	open my $pm, "<", "Peek.pm" or die "Cannot read Peek.pm: $!\n";
 	my $vsn = do { <$pm> =~ m/^\$VERSION\s*=\s*"([0-9._]+)/m; $1 };
 	close   $pm;
 
