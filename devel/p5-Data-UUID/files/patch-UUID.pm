--- UUID.pm.orig	Mon May 27 18:11:13 2002
+++ UUID.pm	Mon May 27 18:12:25 2002
@@ -1,15 +1,14 @@
 package Data::UUID;
 
-use 5.006;
 use strict;
-use warnings;
 use Carp;
 
 require Exporter;
 require DynaLoader;
 use AutoLoader;
 
-our @ISA = qw(Exporter DynaLoader);
+use vars qw(@ISA %EXPORT_TAGS @EXPORT_OK @EXPORT $VERSION $AUTOLOAD);
+@ISA = qw(Exporter DynaLoader);
 
 # Items to export into callers namespace by default. Note: do not export
 # names by default without a very good reason. Use EXPORT_OK instead.
@@ -18,18 +17,18 @@
 # This allows declaration	use Data::UUID ':all';
 # If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
 # will save memory.
-our %EXPORT_TAGS = ( 'all' => [ qw(
+%EXPORT_TAGS = ( 'all' => [ qw(
    NameSpace_DNS
    NameSpace_OID
    NameSpace_URL
    NameSpace_X500
 ) ] );
 
-our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );
+@EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );
 
-our @EXPORT = qw(
+@EXPORT = qw(
 );
-our $VERSION = '0.06';
+$VERSION = '0.06';
 
 sub AUTOLOAD {
     # This AUTOLOAD is used to 'autoload' constants from the constant()
@@ -37,7 +36,6 @@
     # to the AUTOLOAD in AutoLoader.
 
     my $constname;
-    our $AUTOLOAD;
     ($constname = $AUTOLOAD) =~ s/.*:://;
     croak "& not defined" if $constname eq 'constant';
     my $val = constant($constname, @_ ? $_[0] : 0);
