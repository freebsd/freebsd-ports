--- bin/install.rb.orig	Mon Mar 24 07:10:57 2003
+++ bin/install.rb	Thu Dec 16 20:42:15 2004
@@ -8,14 +8,9 @@
 
 $srcdir = CONFIG["srcdir"]
 $version = CONFIG["MAJOR"]+"."+CONFIG["MINOR"]
-$libdir = File.join(CONFIG["libdir"], "ruby", $version)
-$archdir = File.join($libdir, CONFIG["arch"])
-$site_libdir = $:.find {|x| x =~ /site_ruby$/}
-if !$site_libdir
-  $site_libdir = File.join($libdir, "site_ruby")
-elsif $site_libdir !~ Regexp.quote($version)
-  $site_libdir = File.join($site_libdir, $version)
-end
+$libdir = CONFIG["rubylibdir"]
+$archdir = CONFIG["archdir"]
+$site_libdir = CONFIG["sitelibdir"]
 
 def install_rb(srcdir = nil)
   libdir = "lib"
