--- lchat.pl.orig	1998-05-29 12:05:46.000000000 -0700
+++ lchat.pl	2009-02-20 09:33:47.000000000 -0800
@@ -66,6 +66,7 @@
 	# Perl 5 has a special way of getting them via the 'use Socket'
 	# above.
 	$main'pf_inet = &Socket'PF_INET;
+	$main'af_inet = &Socket'AF_INET;
 	$main'sock_stream = &Socket'SOCK_STREAM;
 	local($name, $aliases, $proto) = getprotobyname( 'tcp' );
 	$main'tcp_proto = $proto;
@@ -74,6 +75,7 @@
 	# Perl 4 needs to have the socket.ph file created when perl was
 	# installed.
 	$main'pf_inet = &'PF_INET;
+	$main'af_inet = &'AF_INET;
 	$main'sock_stream = &'SOCK_STREAM;
 	local($name, $aliases, $proto) = getprotobyname( 'tcp' );
 	$main'tcp_proto = $proto;
@@ -85,6 +87,7 @@
 	# Use hardwired versions
 	# but who the heck would change these anyway? (:-)
 	$main'pf_inet = 2;
+	$main'af_inet = 2;
 	$main'sock_stream = 1; # Sigh... On Solaris set this to 2
 	$main'tcp_proto = 6;
 	warn "lchat.pl: using hardwired in network constantants";
@@ -93,7 +96,6 @@
 # Are we using the SOCKS version of perl?
 $using_socks = 0;    # 0=no (default), 1=yes
 
-$sockaddr = 'S n a4 x8';
 if( ! $on_win ){
 	chop( $thishost = `hostname` );
 	if( $thishost eq '' ){
@@ -107,6 +109,54 @@
 	$thishost = 'localhost';
 }
 
+#
+# $packedsocketname = _pack_sin($portnumber, $ipaddress)
+#
+sub _pack_sin
+{
+    my $packed;
+
+    if ( $] =~ /^5\.\d+$/ ) {
+	#
+	# FreeBSD has a slightly different (from the rest of the world)
+	# sockaddr_in definition, so rely on Socket module to handle it.
+	#
+	$packed = &Socket'pack_sockaddr_in(@_[0,1]);
+    } else {
+	#
+	# Old-fashioned way to set up sockaddr_in structure. Not
+	# correct for "modern" FreeBSD (>= 5.X ?)
+	#
+	$packed = pack('S n a4 x8', $main'af_inet, 0, $thisaddr);
+    }
+    return $packed;
+}
+
+#
+# ($port, $ipaddress) = _unpack_sin($packedsocketname)
+#
+sub _unpack_sin
+{
+    my @PA;
+
+    if ( $] =~ /^5\.\d+$/ ) {
+	#
+	# FreeBSD has a slightly different (from the rest of the world)
+	# sockaddr_in definition, so rely on Socket module to handle it.
+	# Docs say "Will croak if the structure does not have AF_INET in
+	# the right place."
+	#
+	@PA = &Socket'unpack_sockaddr_in($_[0]);
+    } else {
+	#
+	# Old-fashioned way to parse sockaddr_in structure. Not
+	# correct for "modern" FreeBSD (>= 5.X ?)
+	#
+	(undef, @PA) = unpack('S n a4 x8', $_[0]);
+    }
+    return @PA;
+}
+
 
 ## &chat'open_port("server.address",$port_number);
 ## opens a named or numbered TCP server
@@ -117,7 +167,7 @@
 
 	# We may be multi-homed, start with 0, fixup once connexion is made
 	$thisaddr = "\0\0\0\0" ;
-	$thisproc = pack($sockaddr, 2, 0, $thisaddr);
+	$thisproc = &_pack_sin(0, $thisaddr);
 
 	if ($server =~ /^(\d+)+\.(\d+)\.(\d+)\.(\d+)$/) {
 		$serveraddr = pack('C4', $1, $2, $3, $4);
@@ -128,7 +178,7 @@
 		}
 		$serveraddr = $x[4];
 	}
-	$serverproc = pack($sockaddr, 2, $port, $serveraddr);
+	$serverproc = &_pack_sin($port, $serveraddr);
 	unless (socket(S, $main'pf_inet, $main'sock_stream, $main'tcp_proto)) {
 		($!) = ($!, close(S)); # close S while saving $!
 		return undef;
@@ -150,9 +200,9 @@
 # We opened with the local address set to ANY, at this stage we know
 # which interface we are using.  This is critical if our machine is
 # multi-homed, with IP forwarding off, so fix-up.
-	local($fam,$lport);
-	($fam,$lport,$thisaddr) = unpack($sockaddr, getsockname(S));
-	$thisproc = pack($sockaddr, 2, 0, $thisaddr);
+	local($lport);
+	($lport,$thisaddr) = &_unpack_sin(getsockname(S));
+	$thisproc = &_pack_sin(0, $thisaddr);
 # end of post-connect fixup
 	select((select(S), $| = 1)[0]);
 	return 1;
@@ -161,13 +211,13 @@
 # Similar to open_port, but does less.  Used for PASV code with ftp.pl
 # -Erez Zadok.
 sub open_newport { ## public
-	local($server, $port, $newsock) = @_;
+	local($server, $port, *newsock) = @_;
 
 	local($serveraddr,$serverproc);
 
 	# We may be multi-homed, start with 0, fixup once connexion is made
 	$thisaddr = "\0\0\0\0" ;
-	$thisproc = pack($sockaddr, 2, 0, $thisaddr);
+	$thisproc = &_pack_sin(0, $thisaddr);
 
 	if ($server =~ /^(\d+)+\.(\d+)\.(\d+)\.(\d+)$/) {
 		$serveraddr = pack('C4', $1, $2, $3, $4);
@@ -178,20 +228,20 @@
 		}
 		$serveraddr = $x[4];
 	}
-	$serverproc = pack($sockaddr, 2, $port, $serveraddr);
+	$serverproc = &_pack_sin($port, $serveraddr);
 
-	unless (connect($newsock, $serverproc)) {
-		($!) = ($!, close($newsock)); # close newsock while saving $!
+	unless (connect(newsock, $serverproc)) {
+		($!) = ($!, close(newsock)); # close newsock while saving $!
 		return undef;
 	}
 # We opened with the local address set to ANY, at this stage we know
 # which interface we are using.  This is critical if our machine is
 # multi-homed, with IP forwarding off, so fix-up.
-	local($fam,$lport);
-	($fam,$lport,$thisaddr) = unpack($sockaddr, getsockname($newsock));
-	$thisproc = pack($sockaddr, 2, 0, $thisaddr);
+	local($lport);
+	($lport,$thisaddr) = &_unpack_sin(getsockname(newsock));
+	$thisproc = &_pack_sin(0, $thisaddr);
 # end of post-connect fixup
-	select((select($newsock), $| = 1)[0]);
+	select((select(newsock), $| = 1)[0]);
 	return 1;
 }
 ##############################################################################
