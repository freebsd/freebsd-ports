--- ri/ri.rb.orig	Sun Mar 25 11:25:57 2001
+++ ri/ri.rb	Thu Apr  5 22:13:35 2001
@@ -31,7 +31,7 @@
 
 include Config
 
-$sitedir = CONFIG["sitedir"]
+$sitedir = File.join(CONFIG["sitedir"], CONFIG["MAJOR"] + "." + CONFIG["MINOR"])
 $datadir = File.join($sitedir, "ri")
 $opdir   = File.join($datadir, "op")
 
