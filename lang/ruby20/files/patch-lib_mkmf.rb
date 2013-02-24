--- lib/mkmf.rb.orig	2012-11-28 04:19:49.000000000 -0800
+++ lib/mkmf.rb	2012-12-03 23:18:58.000000000 -0800
@@ -204,7 +204,7 @@
   $extmk &&= true
   if not $extmk and File.exist?(RbConfig::CONFIG["rubyhdrdir"] + "/ruby/ruby.h")
     $hdrdir = CONFIG["rubyhdrdir"]
-    $topdir = $hdrdir
+    $topdir = $hdrdir + "/" + "#{CONFIG['arch']}/ruby/"
     $top_srcdir = $hdrdir
     $arch_hdrdir = "$(hdrdir)/$(arch)"
   elsif File.exist?(($hdrdir = ($top_srcdir ||= topdir) + "/include")  + "/ruby.h")
