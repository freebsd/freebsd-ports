--- install.rb.orig	Tue Aug 14 12:57:38 2001
+++ install.rb	Sun Nov 24 16:33:13 2002
@@ -19,7 +19,7 @@
 $libdir = File.join(CONFIG["libdir"], "ruby", $version)
 
 $bindir =  CONFIG["bindir"]
-$sitedir = CONFIG["sitedir"] || File.join($libdir, "site_ruby")
+$sitedir = File.join(CONFIG["sitedir"] || File.join($libdir, "site_ruby"), $version)
 
 $realbindir = $bindir
 
