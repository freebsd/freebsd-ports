Index: Fan/TCP/TCP.pm
===================================================================
RCS file: /usr/home/ume/ncvs/src/ftpmirror/Fan/TCP/TCP.pm,v
retrieving revision 1.1.1.1
retrieving revision 1.12
diff -u -r1.1.1.1 -r1.12
--- Fan/TCP/TCP.pm	1999/10/24 10:28:15	1.1.1.1
+++ Fan/TCP/TCP.pm	2000/03/09 13:32:06	1.12
@@ -35,15 +35,16 @@
 package Fan::TCP;
 
 use strict;
-use vars qw($VERSION $LOG
-	$tcp_proto $seq_id $sent_octets $recv_octets);
+use vars qw($VERSION $LOG $seq_id $sent_octets $recv_octets);
 
 use Carp;
 use Socket;
+
+use Socket6;
+
 use AutoLoader 'AUTOLOAD';
 
 $VERSION = '0.03';
-$tcp_proto = (getprotobyname('tcp'))[2];
 
 ;#
 BEGIN {
@@ -463,27 +464,21 @@
 
 	# check local side port #.
 	my $port = $params{tcp_bindport} || $self->{tcp_bindport} || 0;
-	if ($port !~ /^\d+$/) {
-		if (!defined($port = getservbyname($port, 'tcp'))) {
-			my $e = $!.'';
-			$self->error($e, &FATAL);
-			carp("$self: getservbyname($port) - $e");
-			return undef;
-		}
-	}
 
 	# define local side address if bindaddr is not null string.
-	my $addr = inet_aton(
-		$params{tcp_bindaddr} || $self->{tcp_bindaddr} || '0.0.0.0');
-
-	# parameter for bind.
-	my $me = sockaddr_in($port, $addr);
+	my $family = $params{tcp_family} ? $params{tcp_family} : AF_INET;
+	my $tcp_bindaddr = $params{tcp_bindaddr} || $self->{tcp_bindaddr} ||
+			   (($family == AF_INET) ? '0.0.0.0' : '::');
+
+	my ($socktype, $proto, $me, $canonname);
+	($family, $socktype, $proto, $me, $canonname)
+		= getaddrinfo($tcp_bindaddr, $port, $family, SOCK_STREAM);
 
 	# local file handle...
 	local *SOCKET;
 
 	# creating a stream socket.
-	unless (socket(SOCKET, PF_INET, SOCK_STREAM, $tcp_proto)) {
+	unless (socket(SOCKET, $family, $socktype, $proto)) {
 		my $e = $!.'';
 		$self->error($e, &FATAL);
 		carp("$self: socket - $e") if $LOG >= 5;
@@ -539,41 +534,27 @@
 		return undef;
 	}
 
-	# try to parse port number
-	if ($port !~ /^\d+$/) {
-		if (!defined($port = getservbyname($port, 'tcp'))) {
-			my $e = $!.'';
-			$self->error($e, &FATAL);
-			carp("$self: getservbyname($port) - $e");
-			return undef;
-		}
-	}
-
-	# check server name
-	my @addr;
-	if ($host =~ /^(\d+)\.(\d+)\.(\d+).(\d+)$/) {
-		@addr = (pack('C4', $1, $2, $3, $4));
-	} else {
-		if ((@addr = gethostbyname($host)) < 5) {
-			carp("$self: gethostbyname - $?");
-			my $e = $?.'';
-			$self->error($e, &FATAL);
-			carp("$self: gethostbyname - $e");
-			return undef;
-		}
-		splice(@addr, 0, 4);
+	# check server name and try to parse port number
+	my @infos = getaddrinfo($host, $port, AF_UNSPEC, SOCK_STREAM);
+	if ($#infos < 1) {
+		carp("$self: getaddrinfo($host, $port) - $?");
+		my $e = $?.'';
+		$self->error($e, &FATAL);
+		carp("$self: getaddrinfo($host, $port) - $e");
+		return undef;
 	}
 
 	# Perl's bug? once connect fails, we could not any more
 	# connect (connect returns "Invalid Argument"). So we
 	# create/close a socket in each iteration.
-	for my $i (@addr) {
+	while ($#infos >= 1) {
+		my ($family, $socktype, $proto, $peer, $canonname)
+		    = splice(@infos, 0, 5);
 
 		# open socket stores any error
+		$params{tcp_family} = $family;
 		$self->open_socket(%params) || return undef;
 
-		# target address.
-		my $peer = sockaddr_in($port, $i);
 		my $result = undef;
 
 		# do real work.
@@ -758,10 +739,13 @@
 	my $sock = $self->handle;
 
 	if (defined($sock)) {
-		my($port, $a) = sockaddr_in(getsockname($sock));
-		my $addr = join('.', unpack('C4', $a));
-carp("$self sockname=$addr:$port") if $LOG > 7;
-		return wantarray ? ($port, $addr) : "$addr:$port";
+		my $sa = getsockname($sock);
+		my $family = (unpack('CC', $sa))[1];
+		my ($addr, $port) = getnameinfo($sa, NI_NUMERICHOST |
+						     NI_NUMERICSERV);
+		carp("$self sockname=$addr|$port|$family") if $LOG > 7;
+		return wantarray ? ($port, $addr, $family)
+				 : "$addr|$port|$family";
 	}
 	return wantarray ? () : undef;
 }
@@ -772,10 +756,13 @@
 	my $sock = $self->handle;
 
 	if (defined($sock)) {
-		my($port, $a) = sockaddr_in(getpeername($sock));
-		my $addr = join('.', unpack('C4', $a));
-carp("$self sockpeer=$addr:$port") if $LOG > 7;
-		return wantarray ? ($port, $addr) : "$addr:$port";
+		my $sa = getpeername($sock);
+		my $family = (unpack('CC', $sa))[1];
+		my ($addr, $port) = getnameinfo($sa, NI_NUMERICHOST |
+						     NI_NUMERICSERV);
+		carp("$self sockpeer=$addr|$port|$family") if $LOG > 7;
+		return wantarray ? ($port, $addr, $family)
+				 : "$addr|$port|$family";
 	}
 	return wantarray ? () : undef;
 }
