--- migemo-cache.rb.orig	Sat Jul 14 14:51:42 2001
+++ migemo-cache.rb	Sat Jul 14 14:51:58 2001
@@ -16,7 +16,7 @@
   next if pattern == ""
 
   migemo = Migemo.new(static_dict, pattern)
-  migemo.optimize = 3
+  migemo.optimization = 3
   data = Marshal.dump(migemo.regex_tree)
   output = [pattern.length].pack("N") + pattern + 
     [data.length].pack("N") + data
