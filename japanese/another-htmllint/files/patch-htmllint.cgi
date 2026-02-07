--- htmllint.cgi.orig	2018-03-26 05:12:09 UTC
+++ htmllint.cgi
@@ -28,6 +28,8 @@ my $MAC = $^O =~ /MacOS/oi;
 my $OS2; #UNSUPPORTED;
 my $UNIX = !($WIN || $MAC || $OS2);
 
+use lib '%%DATADIR%%';
+use lib '%%DATADIR%%/rule';
 require 'htmllint.env';
 require $LINT_NAME;
 
