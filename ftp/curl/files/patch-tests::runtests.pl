--- tests/runtests.pl.orig	Sat Mar 12 03:40:30 2005
+++ tests/runtests.pl	Sat Mar 12 03:40:39 2005
@@ -29,7 +29,7 @@
 @INC=(@INC, $ENV{'srcdir'}, ".");
 
 require "getpart.pm"; # array functions
-require "valgrind.pm"; # valgrind report parser
+#require "valgrind.pm"; # valgrind report parser
 
 my $srcdir = $ENV{'srcdir'} || '.';
 my $HOSTIP="127.0.0.1";
