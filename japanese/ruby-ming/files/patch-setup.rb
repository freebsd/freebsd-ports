--- setup.rb.orig	2003-09-28 15:35:08.000000000 +0900
+++ setup.rb	2014-01-29 17:12:49.000000000 +0900
@@ -204,7 +204,7 @@
 
 class ConfigTable
 
-  c = ::Config::CONFIG
+  c = ::RbConfig::CONFIG
 
   rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -787,7 +787,7 @@
         raise InstallError, "no ruby extention exists: 'ruby #{$0} setup' first"
   end
 
-  DLEXT = /\.#{ ::Config::CONFIG['DLEXT'] }\z/
+  DLEXT = /\.#{ ::RbConfig::CONFIG['DLEXT'] }\z/
 
   def _ruby_extentions( dir )
     Dir.open(dir) {|d|
