--- gem_prelude.rb.orig	2010-01-29 08:19:47.000000000 +0300
+++ gem_prelude.rb	2010-01-29 08:20:04.000000000 +0300
@@ -115,9 +115,6 @@
       if defined? RUBY_FRAMEWORK_VERSION then
         File.join File.dirname(ConfigMap[:sitedir]), 'Gems',
                   ConfigMap[:ruby_version]
-      elsif RUBY_VERSION > '1.9' then
-        File.join(ConfigMap[:libdir], ConfigMap[:ruby_install_name], 'gems',
-                  ConfigMap[:ruby_version])
       else
         File.join(ConfigMap[:libdir], ruby_engine, 'gems',
                   ConfigMap[:ruby_version])
