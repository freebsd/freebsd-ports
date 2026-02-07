--- Makefile.PL.orig	2020-08-18 12:50:07 UTC
+++ Makefile.PL
@@ -20,6 +20,8 @@ if ($mm_version =~ /_/) {
     die $@ if $@;
 }
 
+my $leave_alone = 1;
+
 sub MY::postamble {
     my $ret = "";
     my $mandir = $Config{installman3dir};
@@ -32,7 +34,7 @@ This manual page has a wrong name, and should be remov
 I can add instructions to the Makefile to remove it when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
@@ -51,7 +53,7 @@ These should be removed.
 I can add instructions to the Makefile to remove them when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
