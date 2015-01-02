--- htmllint.cgi.orig	2014-12-07 10:16:56.651728605 +0900
+++ htmllint.cgi	2014-12-07 10:22:52.118705399 +0900
@@ -28,6 +28,8 @@
 my $OS2; #UNSUPPORTED;
 my $UNIX = !($WIN || $MAC || $OS2);
 
+use lib '%%DATADIR%%';
+use lib '%%DATADIR%%/rule';
 require 'htmllint.env';
 require $LINT_NAME;
 
