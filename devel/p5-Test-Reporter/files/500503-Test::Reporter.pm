--- lib/Test/Reporter.pm.orig	Wed Dec 29 21:41:54 2004
+++ lib/Test/Reporter.pm	Wed Dec 29 22:21:27 2004
@@ -246,7 +246,8 @@
 	my($fh, $file); unless ($fh = $_[0]) {
 		$file = "$dir/$grade.$distribution.$Config{archname}.$Config{osvers}.${\(time)}.$$.rpt";
 		warn $file if $self->debug();
-		open $fh, ">$file" or die __PACKAGE__, ": Can't open report file '$file': $!";
+		open FH, ">$file" or die __PACKAGE__, ": Can't open report file '$file': $!";
+		$fh = \*FH;
 	}
 	print $fh "From: $from\n";
 	print $fh "Subject: $subject\n";
