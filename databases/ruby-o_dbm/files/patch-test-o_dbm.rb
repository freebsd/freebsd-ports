--- test-o_dbm.rb.orig	Thu Dec 11 12:54:12 1997
+++ test-o_dbm.rb	Fri Mar 16 18:29:28 2001
@@ -15,6 +15,3 @@
 
-$:.unshift ENV["HOME"]+"/var/lib/ruby"
-$:.unshift "."
-
-require "./o_dbm"
+require "o_dbm"
 
@@ -27,3 +24,3 @@
 
-odbm = ObjectDBM.new("odbm.test.db")
+odbm = ObjectDBM.new("odbm.test")
 
