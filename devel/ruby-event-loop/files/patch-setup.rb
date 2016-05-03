--- setup.rb.orig	2006-10-19 18:09:26 UTC
+++ setup.rb
@@ -281,7 +281,6 @@ class ConfigTable
     'site-ruby-common' => 'siteruby',     # For backward compatibility
     'site-ruby'        => 'siterubyver',  # For backward compatibility
     'bin-dir'          => 'bindir',
-    'bin-dir'          => 'bindir',
     'rb-dir'           => 'rbdir',
     'so-dir'           => 'sodir',
     'data-dir'         => 'datadir',
@@ -786,7 +785,7 @@ class ToplevelInstaller
     else
       require 'rbconfig'
     end
-    ::Config::CONFIG
+    ::RbConfig::CONFIG
   end
 
   def initialize(ardir_root, config)
