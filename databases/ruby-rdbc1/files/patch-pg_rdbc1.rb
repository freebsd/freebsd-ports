--- pg_rdbc1.rb.orig	Fri May 26 03:24:12 2000
+++ pg_rdbc1.rb	Mon Mar 19 17:44:34 2001
@@ -11,7 +11,7 @@
 require "rdbc1.rb"
 
 module PG_RDBC1
-  require "../postgres/postgres.so"
+  require "postgres"
   include RDBC1
 
   # Driver Creator will inherite me.
