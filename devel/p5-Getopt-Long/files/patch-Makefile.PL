$Id$

--- Makefile.PL.orig	Fri May 24 17:51:36 2002
+++ Makefile.PL	Fri May 24 17:52:52 2002
@@ -5,6 +5,7 @@
 
 require "./lib/Getopt/Long.pm";
 my $version = $Getopt::Long::VERSION_STRING || $Getopt::Long::VERSION;
+my $leave_alone = $Config{installprivlib} =~ m|/libdata/perl/|;
 
 sub MY::postamble {
     my $ret = "";
@@ -18,7 +19,7 @@
 I can add instructions to the Makefile to remove it when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
@@ -37,7 +38,7 @@
 I can add instructions to the Makefile to remove them when you
 install this version.
 EOD
-	my $ans = prompt ("Shall I add the remove instructions?");
+	my $ans = $leave_alone ? "no" : "yes";
 	if ( $ans =~ /^y/i ) {
 	    $ret .= <<EOD;
 install ::
@@ -68,7 +69,7 @@
         ABSTRACT => 'Module to handle parsing command line options',
         ),
 
-	INSTALLDIRS => 'perl',
+	INSTALLDIRS => ($leave_alone ? 'site' : 'perl'),
 	PM 	  => { "lib/newgetopt.pl"  => '$(INST_LIB)/newgetopt.pl',
 		       "lib/Getopt/Long.pm" => '$(INST_LIB)/Getopt/Long.pm',
 #		       "perlcmdline.pod" => '$(INST_LIB)/pod/perlcmdline.pod',
