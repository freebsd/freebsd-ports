--- tools/probe_mecab.pl.orig	2015-04-24 17:31:37 UTC
+++ tools/probe_mecab.pl
@@ -43,7 +43,7 @@ if ($^O eq 'MSWin32') {
 } else {
     # try probing in places where we expect it to be
     my $default_config;
-    foreach my $path qw(/usr/bin /usr/local/bin /opt/local/bin) {
+    foreach my $path ( qw(/usr/bin /usr/local/bin /opt/local/bin) ) {
         my $tmp = File::Spec->catfile($path, 'mecab-config');
         if (-f $tmp && -x _) {
             $default_config = $tmp;
