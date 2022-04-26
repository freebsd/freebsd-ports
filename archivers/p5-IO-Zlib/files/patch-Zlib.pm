--- Zlib.pm.orig	2020-09-13 11:36:35 UTC
+++ Zlib.pm
@@ -287,7 +287,7 @@ use strict;
 use warnings;
 
 use Carp;
-use Fcntl qw(SEEK_SET);
+use constant SEEK_SET => 0;
 use Symbol;
 use Tie::Handle;
 
