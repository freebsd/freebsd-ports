--- instruby.rb.orig	Mon Jun  5 12:55:33 2000
+++ instruby.rb	Thu Sep  7 05:33:39 2000
@@ -85,7 +85,7 @@
 File.install wdir+'/'+CONFIG['LIBRUBY_A'], archlibdir, 0644, true
 
 File.makedirs mandir, true
-File.install "ruby.1", mandir, 0644, true
+File.install "ruby.1", "#{mandir}/#{ruby_install_name}.1", 0644, true 
 Dir.chdir wdir
 File.install "config.h", archlibdir, 0644, true
 File.install "rbconfig.rb", archlibdir, 0644, true
