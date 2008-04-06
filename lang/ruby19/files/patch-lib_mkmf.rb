--- lib/mkmf.rb.orig	2008-01-03 21:11:38.000000000 +0300
+++ lib/mkmf.rb	2008-01-03 21:11:55.000000000 +0300
@@ -148,7 +148,7 @@
 path = File.expand_path($0)
 $extmk = path[0, topdir.size+1] == topdir+"/" && %r"\A(ext|enc|tool)\z" =~ File.dirname(path[topdir.size+1..-1])
 if not $extmk and File.exist?(($hdrdir = RbConfig::CONFIG["rubyhdrdir"]) + "/ruby/ruby.h")
-  $topdir = $hdrdir
+  $topdir = $hdrdir + "/" + "#{CONFIG['arch']}/ruby/"
   $top_srcdir = $hdrdir
   $arch_hdrdir = $hdrdir + "/$(arch)"
 elsif File.exist?(($hdrdir = ($top_srcdir ||= topdir) + "/include")  + "/ruby.h") and
