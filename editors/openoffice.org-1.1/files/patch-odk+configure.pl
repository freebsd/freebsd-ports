Issutracker : #iXXXXX#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : most pop name of installated GNU make is gmake, not make for FreeBSD

Index: configure.pl
===================================================================
RCS file: /cvs/api/odk/configure.pl,v
retrieving revision 1.4.12.3
diff -u -r1.4.12.3 configure.pl
--- odk/configure.pl.orig	18 May 2004 10:02:00 -0000	1.4.12.3
+++ odk/configure.pl	11 Aug 2004 08:21:04 -0000
@@ -19,7 +19,7 @@
 chop ($main::OFFICE_HOME_SUGGESTION);
 
 $main::OO_SDK_MAKE_HOME = "";
-$main::OO_SDK_MAKE_HOME_SUGGESTION = searchprog("make");
+$main::OO_SDK_MAKE_HOME_SUGGESTION = searchprog("gmake");
 $main::makeVersion = "3.79.1";
 $main::correctVersion = 0;
 
@@ -101,7 +101,7 @@
 # prepare GNU make path
 while ( (!$main::correctVersion) &&
 		((! -d "$main::OO_SDK_MAKE_HOME" ) ||
-		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/make"))) )
+		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/gmake"))) )
 {
     print "Enter GNU make ($main::makeVersion or higher) tools directory [$main::OO_SDK_MAKE_HOME_SUGGESTION]: ";
     $main::OO_SDK_MAKE_HOME = <STDIN>;
@@ -111,14 +111,14 @@
 		$main::OO_SDK_MAKE_HOME = $main::OO_SDK_MAKE_HOME_SUGGESTION;
     }
     if ( (! -d "$main::OO_SDK_MAKE_HOME") || 
-		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/make")) )
+		 ((-d "$main::OO_SDK_MAKE_HOME") && (! -e "$main::OO_SDK_MAKE_HOME/gmake")) )
     { 
 		$main::OO_SDK_MAKE_HOME = "";
 		print "Error: GNU make is required, please specify a GNU make tools directory.\n";
     } else 
     {
 		#check version
-		my $testVersion = `$OO_SDK_MAKE_HOME/make --version`;
+		my $testVersion = `$OO_SDK_MAKE_HOME/gmake --version`;
 		if ( $testVersion eq "")
 		{
 			print "The 'make' command found at $main::OO_SDK_MAKE_HOME/make is not GNU Make\n";
