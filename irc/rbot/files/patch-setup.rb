--- setup.rb.orig	2017-12-14 20:26:49 UTC
+++ setup.rb
@@ -282,7 +282,6 @@ class ConfigTable
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
