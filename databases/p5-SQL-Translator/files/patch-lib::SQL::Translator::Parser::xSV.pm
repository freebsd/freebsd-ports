--- lib/SQL/Translator/Parser/xSV.pm.orig	Sun May  9 23:33:46 2004
+++ lib/SQL/Translator/Parser/xSV.pm	Sun May  9 23:34:11 2004
@@ -66,7 +66,7 @@
 # -------------------------------------------------------------------
 
 use strict;
-use vars qw($VERSION @EXPORT);
+use vars qw($VERSION @EXPORT_OK);
 $VERSION = sprintf "%d.%02d", q$Revision: 1.16 $ =~ /(\d+)\.(\d+)/;
 
 use Exporter;
@@ -75,7 +75,7 @@
 use SQL::Translator::Utils qw(debug normalize_name);
 
 use base qw(Exporter);
-@EXPORT = qw(parse);
+@EXPORT_OK = qw(parse);
 
 #
 # Passed a SQL::Translator instance and a string containing the data
