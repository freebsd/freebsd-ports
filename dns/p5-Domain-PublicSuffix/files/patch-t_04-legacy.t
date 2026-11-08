--- t/04-legacy.t.orig	2024-11-26 01:04:07 UTC
+++ t/04-legacy.t
@@ -5,7 +5,7 @@ my $ps = Domain::PublicSuffix->new({
 use Domain::PublicSuffix;
 
 my $ps = Domain::PublicSuffix->new({
-    'dataFile' => 'effective_tld_names.dat'
+    'dataFile' => 't/effective_tld_names.dat'
 });
 is( $ps->getRootDomain('google.com'), 'google.com', 'compatibility' );
 is( $ps->tld(), 'com',                            , 'compatibility-tld' );
