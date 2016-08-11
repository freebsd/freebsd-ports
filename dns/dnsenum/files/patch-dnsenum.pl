--- dnsenum.pl.orig	2016-04-22 00:50:16 UTC
+++ dnsenum.pl
@@ -58,6 +58,8 @@ use Net::Netmask;
 use XML::Writer;
 use Socket;
 use String::Random;
+no if $] >= 5.017011, warnings => 'experimental::smartmatch';
+
 
 my ($ithreads_support, $whois_support, $mech_support, $html_support,$xml_support);
 
@@ -71,7 +73,7 @@ my ($domain, $recur, $table, $extend_b, 
 my ($timeout, $delay, $pages, $ipcount, $ipvalid) = (10, 3, 5, 0, 0);
 my ($output);
 my $writer;
-my $program = 'dnsenum.pl';
+my $program = 'dnsenum';
 my $string_gen = String::Random->new;
 my $wildcards = $string_gen->randpattern("cccccccccccc");
 my @wildcardaddress;
@@ -176,11 +178,6 @@ if ($whois && !defined $whois_support) {
 		"whois queries disabled.\n";
 	$whois = undef;
 }
-if ($whois && !defined $whois_support) {
-	warn "Warning: can't load Net::Whois::IP module, ".
-		"whois queries disabled.\n";
-	$whois = undef;
-}
 if ($output && !defined $xml_support) {
 	warn "Warning: can't load XML::Writer module, ".
 		"xml output disabled.\n";
