--- lib/travis/client.rb.orig	2019-12-03 18:21:17 UTC
+++ lib/travis/client.rb
@@ -1,4 +1,3 @@
-require 'backports/2.0.0' if RUBY_VERSION < '2.0.0'
 require 'travis/client/error'
 require 'travis/client/states'
 require 'travis/client/restartable'
