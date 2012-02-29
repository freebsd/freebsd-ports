--- ./t/version.t.orig	2012-02-29 10:44:30.642824576 -0500
+++ ./t/version.t	2012-02-29 10:45:12.047827564 -0500
@@ -18,12 +18,12 @@
 like($ans[1]->[0]->rdatastr, qr!q: 1,!, 'one query now');
 
 ok(@ans = $g->reply_handler("version.example.com", "IN", "TXT", "192.168.0.10"), "version request, txt");
-like($ans[1]->[0]->rdatastr, qr!v$GeoDNS::VERSION/!, 'got the version back');
+like($ans[1]->[0]->rdatastr, qr!v$GeoDNS::VERSION!, 'got the version back');
 
 ok(sleep 1, 'sleep a second');
 
 ok(@ans = $g->reply_handler("version.example.com", "IN", "ANY", "192.168.0.10"), "version request, any");
-like($ans[1]->[0]->rdatastr, qr!v$GeoDNS::VERSION/!, 'got the version back');
+like($ans[1]->[0]->rdatastr, qr!v$GeoDNS::VERSION!, 'got the version back');
 
 ok(@ans = $g->reply_handler("status.example.com", "IN", "ANY", "192.168.0.10"), "status request, any");
 like($ans[1]->[0]->rdatastr, qr!q: 4,!, 'four queries now');
@@ -38,6 +38,6 @@
 my $x = join "\n", $ans[1]->[0]->char_str_list;
 #warn "[", ref $x, "] $x";
 ok(my $data = decode_json($x), "decode json");
-like($data->{v}, qr!v$GeoDNS::VERSION/!, 'got the version back');
+like($data->{v}, qr!v$GeoDNS::VERSION!, 'got the version back');
 
 done_testing();
