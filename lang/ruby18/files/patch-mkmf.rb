--- lib/mkmf.rb.orig	Mon Nov 28 01:22:53 2005
+++ lib/mkmf.rb	Thu Jan 12 01:35:31 2006
@@ -1153,7 +1153,7 @@
 
   mfile.print <<-SITEINSTALL
 
-site-install: site-install-so site-install-rb
+site-install: site-install-so site-install-rb install
 site-install-so: install-so
 site-install-rb: install-rb
 
