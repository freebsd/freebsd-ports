--- src/contrib/xmlwrapp-0.2.2/configure.pl.orig	Tue Jan 28 18:41:25 2003
+++ src/contrib/xmlwrapp-0.2.2/configure.pl	Tue Jan 28 18:41:43 2003
@@ -191,7 +191,7 @@
     print "$output ";
 
     if ($output =~ /^(\d+\.\d+)\.(\d+)$/) {
-	if ($1 >= 2.4 && $2 >= 7) {
+	if ($1 > 2.4 || ($1 == 2.4 && $2 >= 7)) {
 	    print "[good]\n";
 	} else {
 	    print "[fail]\n";
