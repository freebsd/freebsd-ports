--- scripts/ipupdate.pl	2010-05-12 09:09:48.000000000 +0200
+++ scripts/ipupdate.pl	2009-08-24 15:33:20.000000000 +0200
@@ -24,10 +24,10 @@
 
 sub ipset {
 	my $user = LWP::UserAgent->new(timeout => 30);
-	my $get = GET "http://stuff.xergio.net/ip.php";
+	my $get = GET "http://checkip.dyndns.com/";
 	my $req = $user->request($get);
 	my $out = $req->content();
-	$out =~ s/.*IP real: ([0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?).*/$1/s;
+	$out =~ s/.*IP Address: ([0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?).*/$1/s;
 
 	Irssi::print("%9IP update%_:", MSGLEVEL_CRAP);
 	Irssi::command("set dcc_own_ip $out");
