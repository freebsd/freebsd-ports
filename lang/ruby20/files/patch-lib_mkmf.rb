--- lib/mkmf.rb.orig	2013-06-26 07:03:38.000000000 -0700
+++ lib/mkmf.rb	2013-07-03 17:43:05.000000000 -0700
@@ -226,7 +226,7 @@
   end
   $extmk ||= false
   if not $extmk and File.exist?(($hdrdir = RbConfig::CONFIG["rubyhdrdir"]) + "/ruby/ruby.h")
-    $topdir = $hdrdir
+    $topdir = $hdrdir + "/" + "#{CONFIG['arch']}/ruby/"
     $top_srcdir = $hdrdir
     $arch_hdrdir = RbConfig::CONFIG["rubyarchhdrdir"]
   elsif File.exist?(($hdrdir = ($top_srcdir ||= topdir) + "/include")  + "/ruby.h")
