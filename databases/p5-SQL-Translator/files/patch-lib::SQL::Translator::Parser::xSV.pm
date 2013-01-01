--- ./lib/SQL/Translator/Parser/xSV.pm.orig	2009-02-13 13:35:07.000000000 +0100
+++ ./lib/SQL/Translator/Parser/xSV.pm	2009-03-10 15:19:30.000000000 +0100
@@ -64,7 +64,7 @@ C<SQL::Translator::Utils::normalize_name
 
 use strict;
 use warnings;
-our @EXPORT;
+our @EXPORT_OK;
 our $VERSION = '1.59';
 
 use Exporter;
@@ -73,7 +73,7 @@ use Text::RecordParser;
 use SQL::Translator::Utils qw(debug normalize_name);
 
 use base qw(Exporter);
-@EXPORT = qw(parse);
+@EXPORT_OK = qw(parse);
 
 #
 # Passed a SQL::Translator instance and a string containing the data
