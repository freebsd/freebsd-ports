--- htmllint.cgi.orig	Wed Aug 23 19:19:28 2000
+++ htmllint.cgi	Fri Sep 29 14:41:55 2000
@@ -1,4 +1,4 @@
-#!/usr/local/bin/perl
+#!/usr/bin/perl
 
 # CGI script for Another HTML-lint gateway ###################
 
@@ -26,6 +26,8 @@
 #$OS2 = UNSUPPORTED;
 $UNIX = !($WIN || $MAC || $OS2);
 
+use lib '%PREFIX%/share/htmllint';
+use lib '%PREFIX%/share/htmllint/rule';
 require 'htmllint.env';
 require $LINT_NAME;
 
