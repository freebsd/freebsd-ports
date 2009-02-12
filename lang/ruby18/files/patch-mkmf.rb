--- lib/mkmf.rb.orig	2009-02-12 01:18:14.000000000 +0300
+++ lib/mkmf.rb	2009-02-12 01:19:47.000000000 +0300
@@ -132,9 +132,13 @@
 
 topdir = File.dirname(libdir = File.dirname(__FILE__))
 extdir = File.expand_path("ext", topdir)
+setuparchdir = topdir + \
+  "/#{Config::CONFIG["ruby_version"]}/#{Config::CONFIG["arch"]}"
 $extmk = File.expand_path($0)[0, extdir.size+1] == extdir+"/"
-if not $extmk and File.exist?(($hdrdir = Config::CONFIG["archdir"]) + "/ruby.h")
-  $topdir = $hdrdir
+if not $extmk and File.exist?(setuparchdir + "/ruby.h")
+  $hdrdir = $topdir = setuparchdir
+elsif not $extmk and File.exist?(Config::CONFIG["archdir"] + "/ruby.h")
+  $topdir = $hdrdir = Config::CONFIG["archdir"]
 elsif File.exist?(($hdrdir = ($top_srcdir ||= topdir))  + "/ruby.h") and
     File.exist?(($topdir ||= Config::CONFIG["topdir"]) + "/config.h")
 else
@@ -1554,7 +1558,7 @@
 
   mfile.print <<-SITEINSTALL
 
-site-install: site-install-so site-install-rb
+site-install: site-install-so site-install-rb install
 site-install-so: install-so
 site-install-rb: install-rb
 
