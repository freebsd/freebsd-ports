--- cvsweb.cgi.orig	Thu Jan 11 11:00:55 2001
+++ cvsweb.cgi	Thu Jan 11 12:35:36 2001
@@ -1,2 +1,2 @@
-#!/usr/bin/perl -wT
+#!!!PERL!! -wT
 #
@@ -148,3 +148,3 @@
      "$mydir/cvsweb.conf",
-     '/usr/local/etc/cvsweb/cvsweb.conf'
+     '!!PREFIX!!/etc/cvsweb/cvsweb.conf'
     ) {
