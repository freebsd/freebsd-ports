--- cvsweb.cgi.orig	Sat May  8 23:13:40 2004
+++ cvsweb.cgi	Wed May 12 15:27:34 2004
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -T
+#!!!PERL!! -wT
 #
 # cvsweb - a CGI interface to CVS trees.
 #
@@ -214,7 +214,7 @@
 
 # == EDIT this ==
 # Locations to search for user configuration, in order:
-for (catfile($mydir, 'cvsweb.conf'), '/usr/local/etc/cvsweb/cvsweb.conf') {
+for (catfile($mydir, 'cvsweb.conf'), '!!PREFIX!!/etc/cvsweb/cvsweb.conf') {
   if (-r $_) {
     $config = $_;
     last;
