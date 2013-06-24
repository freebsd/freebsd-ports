--- config/config_ruby.rb.orig	2013-02-14 14:27:39.000000000 +0100
+++ config/config_ruby.rb	2013-06-24 18:34:23.000000000 +0200
@@ -1,18 +1,18 @@
 require 'rbconfig'
 
-CONFIG = Config::MAKEFILE_CONFIG
+CONFIG = RbConfig::MAKEFILE_CONFIG
 
 
 case ARGV[0]
 when "archdir"
-    puts Config::expand(CONFIG["archdir"])
+    puts RbConfig::expand(CONFIG["archdir"])
 when "lib"
-    puts Config::expand(CONFIG["libdir"])
+    puts RbConfig::expand(CONFIG["libdir"])
 when "vendorarchdir"
-    puts Config::expand(CONFIG["vendorarchdir"])
+    puts RbConfig::expand(CONFIG["vendorarchdir"])
 when "sitearchdir"
-    puts Config::expand(CONFIG["sitearchdir"])
+    puts RbConfig::expand(CONFIG["sitearchdir"])
 when "sitelib"
-    puts Config::expand(CONFIG["sitedir"])
+    puts RbConfig::expand(CONFIG["sitedir"])
 end
 
