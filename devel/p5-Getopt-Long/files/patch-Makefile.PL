--- Makefile.PL.orig	2019-08-12 15:08:17 UTC
+++ Makefile.PL
@@ -12,6 +12,7 @@ use ExtUtils::MakeMaker 5.0;
 use lib "./lib";
 use Getopt::Long;
 my $version = "2.51";
+my $leave_alone = 1;
 
 my $mm_version = $ExtUtils::MakeMaker::VERSION;
 if ($mm_version =~ /_/) {
@@ -32,7 +33,7 @@ This manual page has a wrong name, and s
 I can add instructions to the Makefile to remove it when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
@@ -51,7 +52,7 @@ These should be removed.
 I can add instructions to the Makefile to remove them when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
