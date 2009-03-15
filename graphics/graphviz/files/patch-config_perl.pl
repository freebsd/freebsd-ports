--- config/config_perl.pl.orig	2008-07-14 14:54:04.000000000 +0200
+++ config/config_perl.pl	2009-03-15 11:08:29.000000000 +0100
@@ -11,5 +11,5 @@
 	print "-I$archlib/CORE";
 }
 if ($ARGV[0] eq "PERL_INSTALL_DIR") {
-	print "$Config{vendorarch}"
+	print "$Config{sitearch}"
 }
