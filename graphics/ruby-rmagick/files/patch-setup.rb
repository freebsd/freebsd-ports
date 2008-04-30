--- setup.rb.orig	2006-04-27 02:28:12.000000000 +0400
+++ setup.rb	2008-04-29 21:18:38.101609901 +0400
@@ -147,7 +147,7 @@
   def standard_entries(rbconfig)
     c = rbconfig
 
-    rubypath = File.join(c['bindir'], c['ruby_install_name'] + c['EXEEXT'])
+    rubypath = ENV['RUBY'] || File.join(c['bindir'], c['ruby_install_name'] + c['EXEEXT'])
 
     major = c['MAJOR'].to_i
     minor = c['MINOR'].to_i
@@ -227,17 +227,17 @@
                    'the directory for system configuration files'),
       PathItem.new('localstatedir', 'path', parameterize.call(c['localstatedir']),
                    'the directory for local state data'),
-      PathItem.new('libruby', 'path', libruby,
+      PathItem.new('libruby', 'path', parameterize.call(libruby),
                    'the directory for ruby libraries'),
-      PathItem.new('librubyver', 'path', librubyver,
+      PathItem.new('librubyver', 'path', parameterize.call(librubyver),
                    'the directory for standard ruby libraries'),
-      PathItem.new('librubyverarch', 'path', librubyverarch,
+      PathItem.new('librubyverarch', 'path', parameterize.call(librubyverarch),
                    'the directory for standard ruby extensions'),
-      PathItem.new('siteruby', 'path', siteruby,
+      PathItem.new('siteruby', 'path', parameterize.call(siteruby),
           'the directory for version-independent aux ruby libraries'),
-      PathItem.new('siterubyver', 'path', siterubyver,
+      PathItem.new('siterubyver', 'path', parameterize.call(siterubyver),
                    'the directory for aux ruby libraries'),
-      PathItem.new('siterubyverarch', 'path', siterubyverarch,
+      PathItem.new('siterubyverarch', 'path', parameterize.call(siterubyverarch),
                    'the directory for aux ruby binaries'),
       PathItem.new('rbdir', 'path', '$siterubyver',
                    'the directory for ruby scripts'),
