--- Makefile.PL.orig	2012-05-24 10:33:05 UTC
+++ Makefile.PL
@@ -1,17 +1,6 @@
 
 use strict;
 
-BEGIN {
-    if ( open MEMCACHED, "memcached -i |" ) {
-        chomp( my $header = <MEMCACHED> );
-        print "Using $header for tests!\n";
-    }
-
-    else {
-        print "No executable memcached found: $!\n";
-        print "Many tests will fail, install can only be forced!\n";
-    }
-}
 
 use ExtUtils::MakeMaker;
 eval "use Devel::Required";
