--- install.rb.orig	Sun Mar 25 11:48:54 2001
+++ install.rb	Thu Apr  5 21:49:24 2001
@@ -16,16 +16,18 @@
 # This sets up a standard environment for any sub-installs as well
 
 $version = CONFIG["MAJOR"]+"."+CONFIG["MINOR"]
-$libdir = File.join(CONFIG["libdir"], "ruby", $version)
+#$libdir = File.join(CONFIG["libdir"], "ruby", $version)
 
 $bindir =  CONFIG["bindir"]
-$sitedir = CONFIG["sitedir"] || File.join($libdir, "site_ruby")
+#$sitedir = CONFIG["sitedir"] || File.join($libdir, "site_ruby")
+$sitedir = File.join(CONFIG["sitedir"], $version)
 $ri_dest = File.join($sitedir, "ri")
 $ri_op = File.join($ri_dest, "op")
 
 
 # This is old stuff, but we need it to get tidy up a previous installation
 
+=begin
 $site_libdir = $:.find {|x| x =~ /site_ruby$/}
 
 if !$site_libdir
@@ -33,7 +35,9 @@
 elsif $site_libdir !~ Regexp.quote($version)
   $site_libdir = File.join($site_libdir, $version)
 end
+=end
 
+$site_libdir = $sitedir
 
 ##
 # Install an output formatter
