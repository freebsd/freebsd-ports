--- ext/ruby_prof/extconf.rb.orig	2015-04-13 15:15:09 UTC
+++ ext/ruby_prof/extconf.rb
@@ -1,3 +1,4 @@
+require 'rubygems'
 require "mkmf"
 
 if RUBY_VERSION < "1.9.3"
