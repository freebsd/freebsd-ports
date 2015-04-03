--- ext/fastthread/extconf.rb.orig	2015-01-23 16:43:26.000000000 +0000
+++ ext/fastthread/extconf.rb	2015-01-23 16:43:33.000000000 +0000
@@ -10,7 +10,7 @@
 else
   require 'rbconfig'
   File.open('Makefile', 'w') do |stream|
-    Config::CONFIG.each do |key, value|
+    RbConfig::CONFIG.each do |key, value|
       stream.puts "#{key} = #{value}"
     end
     stream.puts
