--- lib/gh.rb.orig	2019-12-03 16:28:14 UTC
+++ lib/gh.rb
@@ -1,5 +1,4 @@
 require 'gh/version'
-require 'backports' if RUBY_VERSION < '2.1'
 require 'forwardable'
 
 module GH
