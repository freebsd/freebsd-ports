--- bin/install.rb.orig	Tue Aug 24 18:05:55 2004
+++ bin/install.rb	Tue Aug 24 18:22:07 2004
@@ -10,12 +10,7 @@
 $version = CONFIG["MAJOR"]+"."+CONFIG["MINOR"]
 $libdir = File.join(CONFIG["libdir"], "ruby", $version)
 $archdir = File.join($libdir, CONFIG["arch"])
-$site_libdir = $:.find {|x| x =~ /site_ruby$/}
-if !$site_libdir
-  $site_libdir = File.join($libdir, "site_ruby")
-elsif $site_libdir !~ Regexp.quote($version)
-  $site_libdir = File.join($site_libdir, $version)
-end
+$site_libdir = CONFIG["sitelibdir"]
 
 def install_rb(srcdir = nil)
   libdir = "lib"
