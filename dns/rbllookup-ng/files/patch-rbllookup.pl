--- rbllookup.pl.orig	2014-05-11 10:08:39 UTC
+++ rbllookup.pl
@@ -39,7 +39,7 @@ print "\n";
 
 # Reading configuration
 
-my $configfile="/etc/rbllookup.conf";
+my $configfile="%%PREFIX%%/etc/rbllookup.conf";
 my $test=0;
 my $parallel=32;
 my $timeout=5;
