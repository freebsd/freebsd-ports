--- t/01-core.t.orig	2024-11-26 01:04:07 UTC
+++ t/01-core.t
@@ -30,7 +30,7 @@ $ps = Domain::PublicSuffix->new({ 
 is( $ps->tld(), 'com',                                      , 'domain-error' );
 
 $ps = Domain::PublicSuffix->new({ 
-    'data_file' => 'effective_tld_names.dat'
+    'data_file' => 't/effective_tld_names.dat'
 });
 
 is( ref($ps), 'Domain::PublicSuffix',                       , 'create-external-object' );
