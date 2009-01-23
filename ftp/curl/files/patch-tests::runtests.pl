diff -urN -x .svn ../../vendor/curl/tests/runtests.pl ./tests/runtests.pl
--- ../../vendor/curl/tests/runtests.pl	2008-10-27 22:11:37.000000000 +0200
+++ ./tests/runtests.pl	2009-01-21 16:12:22.000000000 +0200
@@ -88,7 +88,7 @@
     );
 
 require "getpart.pm"; # array functions
-require "valgrind.pm"; # valgrind report parser
+#require "valgrind.pm"; # valgrind report parser
 require "ftp.pm";
 
 my $HOSTIP="127.0.0.1";   # address on which the test server listens
