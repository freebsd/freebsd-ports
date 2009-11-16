--- lib/Net/Domain/ExpireDate.pm.orig	2009-11-16 00:19:34.303198027 +0900
+++ lib/Net/Domain/ExpireDate.pm	2009-11-16 00:23:56.700841208 +0900
@@ -130,6 +130,9 @@
     if ($tld eq 'ru' || $tld eq 'su') {
 	return (dates_int_ru( $whois ));
     } else { # 'com', 'net', 'org', 'biz', 'info', 'us', 'uk', 'cc'
+	if ( $tld eq 'jp' ) {
+	  eval {$whois = Encode::encode('iso-2022-jp', $whois) if Encode::is_utf8($whois);};
+	}
 	my $expdate = $flags & FLG_EXPDATE ? expdate_int_cno( $whois ) : undef;
 	my $credate = $flags & FLG_CREDATE ? credate_int_cno( $whois ) : undef;
 	return ($credate, $expdate);
@@ -284,7 +287,9 @@
     # [whois.jprs.jp]                   [....]                      2006/12/31
     } elsif ($whois =~ m|\[\x1b\x24\x42\x4d\x2d\x38\x7a\x34\x7c\x38\x42\x1b\x28\x42\]\s+(\d{4})/(\d{2})/(\d{2})|s) {
         $rulenum = 7.4; $Y = $1; $m = $2; $d = $3;
-    }
+    } elsif ($whois =~ m|\[\x1b\x24\x42\x3e\x75\x42\x56\x1b\x28\x42\]\s+.*\s+\((\d{4})/(\d{2})/(\d{2})|s) {
+	$rulenum = 7.5; $Y = $1; $m = $2; $d = $3;
+      }
 
     unless ($rulenum) {
 	warn "Can't recognise expiration date format: $whois\n";
