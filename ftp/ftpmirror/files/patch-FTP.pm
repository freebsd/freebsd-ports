Index: Fan/FTP/FTP.pm
===================================================================
RCS file: /usr/home/ume/ncvs/src/ftpmirror/Fan/FTP/FTP.pm,v
retrieving revision 1.1.1.2
retrieving revision 1.6
diff -u -r1.1.1.2 -r1.6
--- Fan/FTP/FTP.pm	2000/03/03 07:35:58	1.1.1.2
+++ Fan/FTP/FTP.pm	2000/03/09 13:32:04	1.6
@@ -60,6 +60,9 @@
 
 use Carp;
 use Socket;
+
+use Socket6;
+
 use Fan::TCP;
 use AutoLoader 'AUTOLOAD';
 
@@ -390,7 +393,7 @@
 	$self->clearerror || return undef;
 	$self->cleardataconn;	# always success
 
-	my($port, $addr) = $self->sockname;
+	my ($port, $addr, $family) = $self->sockname;
 
 	my $acpt = Fan::TCP->new();
 	unless (defined($acpt)) {
@@ -398,20 +401,28 @@
 		return undef;
 	}
 
-	unless ($acpt->do_server(tcp_bindaddr => $addr)) {
+	unless ($acpt->do_server(tcp_family => $family,
+				 tcp_bindaddr => $addr)) {
 		warn("Fan::TCP->do_server failed");
 		return undef;
 	}
 
-	($port, $addr) = $acpt->sockname;
-	unless ($addr =~ tr/./,/ == 3) {
-		warn("ADDRESS=$addr must have just 3 dots");
-		return undef;
+	($port, $addr, $family) = $acpt->sockname;
+	my $command;
+	if ($family == AF_INET) {
+		unless ($addr =~ tr/./,/ == 3) {
+			warn("ADDRESS=$addr must have just 3 dots");
+			return undef;
+		}
+		$addr .= sprintf(",%d,%d", ($port >> 8) & 0xff, $port & 0xff);
+		$command = 'PORT';
+	} else {
+		$addr = "|2|$addr|$port|";
+		$command = 'EPRT';
 	}
-	$addr .= sprintf(",%d,%d", ($port >> 8) & 0xff, $port & 0xff);
 
-	unless ($self->putreq("PORT $addr") =~ /^2/) {
-		warn("PORT command failed\n") if $LOG > 5;
+	unless ($self->putreq("$command $addr") =~ /^2/) {
+		warn("$command command failed\n") if $LOG > 5;
 		$self->error($self->{lastmesg});
 		return undef;
 	}
@@ -437,12 +448,20 @@
 ;#
 sub pasv ($) {
 	my $self = shift;
-	my $a_regexp = '\((\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\)';
 
 	$self->clearerror	&&
 	$self->cleardataconn	|| return undef;
 
-	if ($self->putreq("PASV") !~ /^2/) {
+	my $family = ($self->sockname)[2];
+	my ($a_regexp, $command);
+	if ($family == AF_INET) {
+		$a_regexp = '\((\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\)';
+		$command = 'PASV';
+	} else {
+		$a_regexp = '\([^\d\s]{3}(\d+)[^\d\s]\)';
+		$command = 'EPSV';
+	}
+	if ($self->putreq($command) !~ /^2/) {
 		$self->error($self->{lastmesg});
 		return undef;
 	}
@@ -452,11 +471,18 @@
 	}
 
 	my $bindaddr = $self->{ftp_bindaddr};
-	my $port = $5 * 256 + $6;
-	my $addr = join('.', $1, $2, $3, $4);
+	my ($port, $addr);
+	if ($family == AF_INET) {
+		$port = $5 * 256 + $6;
+		$addr = join('.', $1, $2, $3, $4);
+	} else {
+		$port = $1;
+		$addr = ($self->peername)[1];
+	}
 	my $data = Fan::TCP->new();
 
 	$data && $data->do_client(
+		tcp_family => $family,
 		tcp_bindaddr => $bindaddr,
 		tcp_host => $addr,
 		tcp_port => $port
