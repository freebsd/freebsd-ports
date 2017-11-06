--- Makefile.PL.orig	2017-07-24 11:59:06 UTC
+++ Makefile.PL
@@ -33,9 +33,9 @@ my %wm = (
 $ExtUtils::MakeMaker::VERSION > 6.30 and $wm{LICENSE} = "perl";
 
 unless (exists $ENV{AUTOMATED_TESTING} and $ENV{AUTOMATED_TESTING} == 1) {
-    if (prompt ("Do you want to install module DP as a shortcut for Data::Peek ?", "y") =~ m/[yY]/) {
+    {
 	local $/;
-	open my $pm, "<", "Peek.pm" or die "CAnnot read Peek.pm: $!\n";
+	open my $pm, "<", "Peek.pm" or die "Cannot read Peek.pm: $!\n";
 	my $vsn = do { <$pm> =~ m/^\$VERSION\s*=\s*"([0-9._]+)/m; $1 };
 	close   $pm;
 
