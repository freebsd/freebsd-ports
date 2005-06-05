--- tests/runtests.pl.orig	Wed May 18 11:50:16 2005
+++ tests/runtests.pl	Wed May 18 11:50:32 2005
@@ -29,7 +29,7 @@
 @INC=(@INC, $ENV{'srcdir'}, ".");
 
 require "getpart.pm"; # array functions
-require "valgrind.pm"; # valgrind report parser
+#require "valgrind.pm"; # valgrind report parser
 require "ftp.pm";
 
 my $srcdir = $ENV{'srcdir'} || '.';
