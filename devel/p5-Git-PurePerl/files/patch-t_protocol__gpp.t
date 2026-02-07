--- t/protocol_gpp.t.orig	2013-08-26 11:24:05 UTC
+++ t/protocol_gpp.t
@@ -6,6 +6,13 @@ use IO::File;
 use Path::Class;
 use Test::More;
 
+my $socket = IO::Socket::INET->new("www.google.com:80");
+if ($socket) {
+	close ($socket);
+} else {
+	plan skip_all => 'No Internet connection?';
+}
+
 my $directory = 'test-protocol';
 dir($directory)->rmtree;
 
