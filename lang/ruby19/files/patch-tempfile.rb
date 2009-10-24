--- lib/tempfile.rb.orig	2009-07-15 21:57:41.000000000 +1000
+++ lib/tempfile.rb	2009-10-23 21:31:49.159715744 +1100
@@ -137,7 +137,6 @@
     # keep this order for thread safeness
     begin
       if File.exist?(@tmpname)
-        closed? or close
         File.unlink(@tmpname)
       end
       @@cleanlist.delete(@tmpname)
