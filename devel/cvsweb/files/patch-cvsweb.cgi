--- cvsweb.cgi.orig	Fri Sep 27 05:56:05 2002
+++ cvsweb.cgi	Tue Feb 24 23:12:51 2004
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -wT
+#!!!PERL!! -w
 #
 # cvsweb - a CGI interface to CVS trees.
 #
@@ -157,7 +157,7 @@
 
 # == EDIT this ==
 # Locations to search for user configuration, in order:
-for ("$mydir/cvsweb.conf", '/usr/local/etc/cvsweb/cvsweb.conf') {
+for ("$mydir/cvsweb.conf", '!!PREFIX!!/etc/cvsweb/cvsweb.conf') {
 	if (defined($_) && -r $_) {
 		$config = $_;
 		last;
