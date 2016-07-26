--- Zlib.pm.orig	2009-07-14 21:30:41 UTC
+++ Zlib.pm
@@ -289,7 +289,7 @@ use strict;
 use vars qw($VERSION $AUTOLOAD @ISA);
 
 use Carp;
-use Fcntl qw(SEEK_SET);
+use constant SEEK_SET => 0;
 
 my $has_Compress_Zlib;
 my $aliased;
