--- gettext.pm.orig	2011-08-10 15:54:33.000000000 +0400
+++ gettext.pm	2011-08-10 15:54:53.000000000 +0400
@@ -32,6 +32,7 @@
 =cut
 
 use Carp;
+use POSIX qw(:locale_h);
 
 require Exporter;
 require DynaLoader;
