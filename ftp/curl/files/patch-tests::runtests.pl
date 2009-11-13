Description: Do not use valgrind.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-13

--- a/tests/runtests.pl
+++ b/tests/runtests.pl
@@ -88,7 +88,7 @@
     );
 
 require "getpart.pm"; # array functions
-require "valgrind.pm"; # valgrind report parser
+#require "valgrind.pm"; # valgrind report parser
 require "ftp.pm";
 
 my $HOSTIP="127.0.0.1";   # address on which the test server listens
