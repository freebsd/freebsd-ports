--- config/config_perl.pl.orig	2013-02-15 00:27:39.000000000 +1100
+++ config/config_perl.pl	2013-06-18 11:18:34.000000000 +1100
@@ -11,10 +11,9 @@
 	print "-I$archlib/CORE";
 }
 if ($ARGV[0] eq "PERL_INSTALL_DIR") {
-
 	my $d;
 
-	foreach $d qw(installvendorarch vendorarch installsitearch sitearch) {
+	foreach $d ( qw(installvendorarch vendorarch installsitearch sitearch) ) {
 		if (exists($Config{$d}) and defined($Config{$d}) and
 			($Config{$d} ne '') ) {
 			print "$Config{$d}";
