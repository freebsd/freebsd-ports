--- Makefile.PL.orig	Mon Aug  5 13:06:55 2002
+++ Makefile.PL	Tue Aug  6 17:09:56 2002
@@ -13,29 +13,29 @@
 
 # Check if we have internet connection
 # (I lifted this code from LWP... many thanks for this and more!)
-require IO::Socket;
-my $s = IO::Socket::INET->new(
-	PeerAddr => "www.google.com:80",
-	Timeout  => 10,
-);
+#require IO::Socket;
+#my $s = IO::Socket::INET->new(
+#	PeerAddr => "www.google.com:80",
+#	Timeout  => 10,
+#);
 
-if ($s) {
-	close($s);
-
-	print <<EOT;
-
-You appear to be directly connected to the Internet.  I have some tests
-that try to query live nameservers.
-
-EOT
-
-	if (prompt("Do you want to enable these tests?", "y") =~ /^y/i) {
-		open(ENABLED, ">t/online.enabled") || die "Can't touch ./t/online.enabled $!";
-		close(ENABLED);
-	} else {
-		unlink("t/online.enabled"); # just to be shure...
-	}
-}
+#if ($s) {
+#	close($s);
+#
+#	print <<EOT;
+#
+#You appear to be directly connected to the Internet.  I have some tests
+#that try to query live nameservers.
+#
+#EOT
+#
+#	if (prompt("Do you want to enable these tests?", "y") =~ /^y/i) {
+#		open(ENABLED, ">t/online.enabled") || die "Can't touch ./t/online.enabled $!";
+#		close(ENABLED);
+#	} else {
+#		unlink("t/online.enabled"); # just to be shure...
+#	}
+#}
 
 
 WriteMakefile(
