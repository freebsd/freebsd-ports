--- ext/master/lib/puppet/util/puppetdb/char_encoding.rb.orig	2015-10-13 22:23:24 UTC
+++ ext/master/lib/puppet/util/puppetdb/char_encoding.rb
@@ -33,7 +33,7 @@ module CharEncoding
 
 
   def self.utf8_string(str)
-    if RUBY_VERSION =~ /1.8/
+    if RUBY_VERSION =~ /^1\.8/
       # Ruby 1.8 doesn't have String#encode and related methods, and there
       #  appears to be a bug in iconv that will interpret some byte sequences
       #  as 6-byte characters.  Thus, we are forced to resort to some unfortunate
