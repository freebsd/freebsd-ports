--- Makefile.PL.orig	Fri Sep 28 16:13:04 2001
+++ Makefile.PL	Fri Jan 25 14:11:26 2002
@@ -2,7 +2,7 @@
 use ExtUtils::MakeMaker qw(prompt WriteMakefile);
 use File::Path;
 
-my $choice;
+my $choice = 3;
 while (!$choice) {
   $reply = prompt(
 		  "\nWhat do you want to build?\n\n" .
@@ -22,8 +22,6 @@
 push @extlib,'Freesubs' if $choice >= 2;
 push @extlib,'RPC'      if $choice >= 3;
 
-print "\n";
-setup_sitedefs() if prompt("Do you want to install Ace::Browser? ","n") =~ /[yY]/;
 
 my $headers  = "./ace/wh";
 WriteMakefile(
