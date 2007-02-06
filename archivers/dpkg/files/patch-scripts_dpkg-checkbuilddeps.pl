--- scripts/dpkg-checkbuilddeps.pl.orig	Sun Jun 18 18:22:03 2006
+++ scripts/dpkg-checkbuilddeps.pl	Fri Nov 10 16:23:44 2006
@@ -4,7 +4,8 @@
 #use strict;
 use Getopt::Long;
 
-my $dpkglibdir="/usr/lib/dpkg";
+my $dpkglibdir="/usr/lib/dpkg"; # This line modified by Makefile
+my $admindir="/var/lib/dpkg"; # This line modified by Makefile
 push(@INC,$dpkglibdir);
 #my $controlfile;
 require 'controllib.pl';
@@ -79,7 +80,7 @@
 # thanks to Matt Zimmerman. Returns two hash references that
 # are exactly what the other functions need...
 sub parse_status {
-	my $status=shift || "/var/lib/dpkg/status";
+	my $status=shift || "$admindir/status";
 	
 	my %providers;
 	my %version;
