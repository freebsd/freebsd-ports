--- install.pl.orig	Thu Aug 23 21:12:47 2001
+++ install.pl	Thu Aug 23 21:17:01 2001
@@ -251,6 +251,7 @@
 
 $defhtmldir="/usr/local/apache/share/htdocs";
 foreach (
+	"/usr/local/www/data",
 	"/usr/local/apache/share/htdocs",
 	"/usr/local/apache/htdocs",
 	"/opt/apache/share/htdocs", 
@@ -261,6 +262,7 @@
 
 $defcgidir="/usr/local/apache/share/cgi-bin";
 foreach (
+	"/usr/local/www/cgi-bin",
 	"/usr/local/apache/share/cgi-bin",
 	"/usr/local/apache/cgi-bin",
 	"/opt/apache/share/cgi-bin", 
