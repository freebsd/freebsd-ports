--- Makefile.PL.orig	2015-06-11 13:24:35.000000000 +0200
+++ Makefile.PL	2015-06-11 13:25:28.000000000 +0200
@@ -12,6 +12,7 @@ use ExtUtils::MakeMaker 5.0;
 use lib "./lib";
 use Getopt::Long;
 my $version = $Getopt::Long::VERSION_STRING || $Getopt::Long::VERSION;
+my $leave_alone = 1;
 
 sub MY::postamble {
     my $ret = "";
@@ -25,7 +26,7 @@ This manual page has a wrong name, and s
 I can add instructions to the Makefile to remove it when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
@@ -44,7 +45,7 @@ These should be removed.
 I can add instructions to the Makefile to remove them when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
