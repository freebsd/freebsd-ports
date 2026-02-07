--- migemo-cache.rb.orig	2011-08-22 03:56:56.000000000 +0900
+++ migemo-cache.rb	2011-08-22 03:59:20.000000000 +0900
@@ -1,5 +1,4 @@
 require 'migemo'
-$KCODE="e"
 raise if ARGV[0] == nil
 dict = ARGV[0]
 static_dict = MigemoStaticDict.new(dict)
@@ -18,10 +17,10 @@
   migemo = Migemo.new(static_dict, pattern)
   migemo.optimization = 3
   data = Marshal.dump(migemo.regex_tree)
-  output = [pattern.length].pack("N") + pattern + 
-    [data.length].pack("N") + data
+  output = [pattern.bytesize].pack("N") + pattern.dup.force_encoding("ASCII-8BIT") + 
+    [data.bytesize].pack("N") + data
   cache.print output
   index.print [idx].pack("N")
-  idx += output.length
+  idx += output.bytesize
 end
 
