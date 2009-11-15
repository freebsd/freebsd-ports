--- lib/dbd/Pg.rb.orig	2009-07-11 19:07:38.000000000 +0200
+++ lib/dbd/Pg.rb	2009-11-15 10:18:13.000000000 +0100
@@ -31,13 +31,13 @@
 
 begin
     require 'rubygems'
-    gem 'pg'
+    gem 'postgres'
     gem 'dbi'
 rescue Exception => e
 end
 
 require 'dbi'
-require 'pg'
+require 'postgres'
 
 module DBI
     module DBD
