--- Makefile.PL.orig	2006-01-04 15:18:10 UTC
+++ Makefile.PL
@@ -3,7 +3,7 @@ use ExtUtils::MakeMaker qw(prompt WriteM
 use File::Path;
 require 5.8.0;
 
-my $choice;
+my $choice = 3;
 while (!$choice) {
   $reply = prompt(
 		  "\nWhat do you want to build?\n\n" .
@@ -23,8 +23,6 @@ my @extlib = ();
 push @extlib,'Freesubs' if $choice >= 2;
 push @extlib,'RPC'      if $choice >= 3;
 
-print "\n";
-setup_sitedefs() if prompt("Do you want to install Ace::Browser? ","n") =~ /[yY]/;
 
 my $headers  = "./acelib/wh";
 WriteMakefile(
