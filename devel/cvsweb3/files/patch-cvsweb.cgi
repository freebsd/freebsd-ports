--- cvsweb.cgi.orig	Wed Aug  1 18:54:52 2001
+++ cvsweb.cgi	Wed Aug  1 19:09:37 2001
@@ -1,2 +1,2 @@
-#!/usr/bin/perl -wT
+#!!!PERL!! -wT
 #
@@ -155,3 +155,3 @@
 # Locations to search for user configuration, in order:
-for ("$mydir/cvsweb.conf", '/usr/local/etc/cvsweb/cvsweb.conf') {
+for ("$mydir/cvsweb.conf", '!!PREFIX!!/etc/cvsweb/cvsweb.conf') {
 	if (defined($_) && -r $_) {
