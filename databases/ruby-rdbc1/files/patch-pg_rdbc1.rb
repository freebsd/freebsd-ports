--- pg_rdbc1.rb.orig	2000-05-26 03:24:12 UTC
+++ pg_rdbc1.rb
@@ -11,7 +11,7 @@
 require "rdbc1.rb"
 
 module PG_RDBC1
-  require "../postgres/postgres.so"
+  require "postgres"
   include RDBC1
 
   # Driver Creator will inherite me.
