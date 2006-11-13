--- rbllookup.pl.orig	Mon Nov 13 23:55:52 2006
+++ rbllookup.pl	Tue Nov 14 00:04:11 2006
@@ -39,7 +39,7 @@
 
 # Reading configuration
 
-my $configfile="/etc/rbllookup.conf";
+my $configfile="%%PREFIX%%/etc/rbllookup.conf";
 my $test=0;
 my $parallel=32;
 my $timeout=5;
