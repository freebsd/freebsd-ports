--- Makefile.PL.orig	Fri Feb 14 22:55:27 2003
+++ Makefile.PL	Mon May  5 12:43:19 2003
@@ -10,11 +10,3 @@
   }
 );
 
-$connstr = prompt ("DBI Connection String?", "DBI:mysql:test");
-$userid  = prompt ("User ID?", "");
-$passwd  = prompt ("Password?", "");
-
-open(PWD, ">PWD") || die "Could not open PWD for writing!";
-print PWD $connstr, "\n";
-print PWD $userid, "\n";
-print PWD $passwd, "\n";
