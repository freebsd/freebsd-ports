--- test.pl.orig	2005-09-28 14:45:55.000000000 +0000
+++ test.pl
@@ -40,6 +40,8 @@ if ($^O =~ /MSWin32/) {
 	$id = $cddb->getdiscid(0);
 } elsif ($^O =~ /freebsd/) {
 	$id = $cddb->getdiscid('/dev/acd0');
+} elsif ($^O =~ /dragonfly/) {
+	$id = $cddb->getdiscid('/dev/cd0');
 } else {
 	$id = $cddb->getdiscid('/dev/cdrom');
 }
@@ -51,6 +53,8 @@ if ($^O =~ /MSWin32/) {
 	$id = Net::FreeDB::getdiscid(0);
 } elsif ($^O =~ /freebsd/) {
 	$id = Net::FreeDB::getdiscid('/dev/acd0');
+} elsif ($^O =~ /dragonfly/) {
+	$id = Net::FreeDB::getdiscid('/dev/cd0');
 } else {
 	$id = Net::FreeDB::getdiscid('/dev/cdrom');
 }
@@ -62,6 +66,8 @@ if ($^O =~ /MSWin32/) {
 	$id = Net::FreeDB::getdiscdata(0);
 } elsif ($^O =~ /freebsd/) {
 	$id = Net::FreeDB::getdiscdata('/dev/acd0');
+} elsif ($^O =~ /dragonfly/) {
+	$id = Net::FreeDB::getdiscdata('/dev/cd0');
 } else {
 	$id = Net::FreeDB::getdiscdata('/dev/cdrom');
 }
