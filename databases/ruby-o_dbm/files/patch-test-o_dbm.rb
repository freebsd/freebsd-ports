--- test-o_dbm.rb.orig	Sun Mar 18 22:16:26 2001
+++ test-o_dbm.rb	Mon Mar 19 20:33:11 2001
@@ -15,6 +15,3 @@
 
-$:.unshift ENV["HOME"]+"/var/lib/ruby"
-$:.unshift "."
-
-require "./o_dbm"
+require "o_dbm"
 
