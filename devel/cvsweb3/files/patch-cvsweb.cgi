Index: cvsweb.cgi
===================================================================
RCS file: /home/ncvs/projects/cvsweb/cvsweb.cgi,v
retrieving revision 1.119
diff -a -u -r1.119 cvsweb.cgi
--- cvsweb.cgi	23 Jul 2002 13:58:32 -0000	1.119
+++ cvsweb.cgi	23 Jul 2002 14:16:12 -0000
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -wT
+#!!!PERL!! -wT
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
