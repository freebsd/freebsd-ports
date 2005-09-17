--- lib/Class/DBI/AsForm.pm.orig	Wed Sep  7 11:53:35 2005
+++ lib/Class/DBI/AsForm.pm	Wed Sep  7 11:55:48 2005
@@ -1,18 +1,17 @@
 package Class::DBI::AsForm;
 
-use 5.006;
-our $VERSION = '2.42';
+use vars qw($VERSION $OLD_STYLE @EXPORT);
+$VERSION = '2.42';
 
 use strict;
-use warnings;
 
 use base 'Exporter';
 
 use Class::DBI::Plugin::Type ();
 use HTML::Element;
 
-our $OLD_STYLE = 0;
-our @EXPORT    = qw( to_cgi to_field _to_textarea _to_textfield _to_select
+$OLD_STYLE = 0;
+@EXPORT    = qw( to_cgi to_field _to_textarea _to_textfield _to_select
 	type_of );
 
 =head1 NAME
