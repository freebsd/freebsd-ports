--- Zlib.pm.orig	Sun Feb 13 00:43:08 2005
+++ Zlib.pm	Sun Feb 13 00:43:30 2005
@@ -297,7 +297,7 @@
 use vars qw($VERSION $AUTOLOAD @ISA);
 
 use Carp;
-use Fcntl qw(SEEK_SET);
+use constant SEEK_SET => 0;
 
 my $has_Compress_Zlib;
 my $aliased;
