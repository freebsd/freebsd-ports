--- lib/mkmf.rb.orig	Thu Aug 17 09:47:50 2006
+++ lib/mkmf.rb	Wed Aug 30 13:14:44 2006
@@ -113,8 +113,12 @@
 
 topdir = File.dirname(libdir = File.dirname(__FILE__))
 extdir = File.expand_path("ext", topdir)
+setuparchdir = topdir + \
+  "/#{Config::CONFIG["ruby_version"]}/#{Config::CONFIG["arch"]}"
 $extmk = File.expand_path($0)[0, extdir.size+1] == extdir+"/"
-if not $extmk and File.exist?(Config::CONFIG["archdir"] + "/ruby.h")
+if not $extmk and File.exist?(setuparchdir + "/ruby.h")
+  $hdrdir = $topdir = setuparchdir
+elsif not $extmk and File.exist?(Config::CONFIG["archdir"] + "/ruby.h")
   $hdrdir = $topdir = Config::CONFIG["archdir"]
 elsif File.exist?(($top_srcdir ||= topdir)  + "/ruby.h") and
     File.exist?(($topdir ||= Config::CONFIG["topdir"]) + "/config.h")
@@ -1281,7 +1285,7 @@
 
   mfile.print <<-SITEINSTALL
 
-site-install: site-install-so site-install-rb
+site-install: site-install-so site-install-rb install
 site-install-so: install-so
 site-install-rb: install-rb
 
