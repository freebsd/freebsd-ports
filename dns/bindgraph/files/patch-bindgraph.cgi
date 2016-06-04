--- bindgraph.cgi.orig	2016-05-23 13:30:02 UTC
+++ bindgraph.cgi
@@ -8,13 +8,14 @@
 
 use RRDs;
 use strict;
+use POSIX qw(uname);
 
 my $VERSION = '0.1';
 
 # hostname. will be printed in the HTML page
-my $hostname = 'hostname.example.net (please edit bindgraph.cgi)';
+my $hostname = (POSIX::uname())[1];
 # path of the RRD database
-my $rrd = '/var/www/as112/rrd/bindgraph.rrd';
+my $rrd = '%%DATADIR%%/bindgraph.rrd';
 # temporary directory where the images will be saved
 my $tmp_dir = '/tmp/bindgraph';
 
@@ -89,6 +90,10 @@ sub graph($$$;$) {
 		}
 	}
 
+	my $comment = 'last update: ' . localtime(last_update($rrd))
+			. '    graph created on ' . localtime(time) . '\r';
+	$comment =~ s|:|\\:|g unless $RRDs::VERSION < 1.199908;
+
 	my ($text, $xs, $ys) = RRDs::graph(
 		$file,
 		'--imgformat', 'PNG',
@@ -102,8 +107,7 @@ sub graph($$$;$) {
 		@rrdef,
 		@rrprint,
 		'COMMENT:\s',
-		'COMMENT:last update: ' . localtime(last_update($rrd))
-			. '    graph created on ' . localtime(time) . '\r',
+		'COMMENT:' . $comment,
 	);
 	my $err = RRDs::error;
 	die_fatal("RRDs::graph($file, ...): $err") if $err;
@@ -209,6 +213,7 @@ sub main {
 	$uri =~ s#/#,#g;
 	$uri =~ s#~#tilde,#g;
 
+	mkdir("$tmp_dir", 0755);
 	die_fatal("ERROR: $tmp_dir does not exist") if not -d $tmp_dir;
 
 	if (not -d "$tmp_dir/$uri") {
