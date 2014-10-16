--- test.pl.orig	2014-10-14 17:57:41.459066370 +0600
+++ test.pl	2014-10-14 17:59:37.614059704 +0600
@@ -38,6 +38,8 @@
 	$id = $cddb->getdiscid(0);
 } elsif ($^O =~ /freebsd/) {
 	$id = $cddb->getdiscid('/dev/acd0');
+} elsif ($^O =~ /dragonfly/) {
+	$id = $cddb->getdiscid('/dev/cd0');
 } else {
 	$id = $cddb->getdiscid('/dev/cdrom');
 }
@@ -49,6 +51,8 @@
 	$id = Net::FreeDB::getdiscid(0);
 } elsif ($^O =~ /freebsd/) {
 	$id = Net::FreeDB::getdiscid('/dev/acd0');
+} elsif ($^O =~ /dragonfly/) {
+	$id = Net::FreeDB::getdiscid('/dev/cd0');
 } else { $id = Net::FreeDB::getdiscid('/dev/cdrom');
 }
 ok($id);
@@ -59,6 +63,8 @@
 	$id = Net::FreeDB::getdiscdata(0);
 } elsif ($^O =~ /freebsd/) {
 	$id = Net::FreeDB::getdiscdata('/dev/acd0');
+} elsif ($^O =~ /dragonfly/) {
+	$id = Net::FreeDB::getdiscdata('/dev/cd0');
 } else {
 	$id = Net::FreeDB::getdiscdata('/dev/cdrom');
 }
