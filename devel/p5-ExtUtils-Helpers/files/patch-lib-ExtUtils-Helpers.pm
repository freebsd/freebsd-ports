--- lib/ExtUtils/Helpers.pm.orig	2013-04-12 22:39:09.000000000 +0800
+++ lib/ExtUtils/Helpers.pm	2013-04-14 18:30:31.986773914 +0800
@@ -39,7 +39,8 @@
 	my ($vols, $dirs, $file) = splitpath(canonpath($filename));
 	$file = basename($file, qw/.pm .pod/);
 	$dirs = abs2rel($dirs, $base);
-	return join $separator, $dirs, "$file.3pm";
+	$dirs =~ s|/|$separator|g;
+	return join $separator, $dirs, "$file.3";
 }
 
 1;
