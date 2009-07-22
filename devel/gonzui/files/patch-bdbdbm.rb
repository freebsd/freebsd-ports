--- gonzui/bdbdbm.rb.orig	2005-03-02 18:26:12.000000000 +0900
+++ gonzui/bdbdbm.rb	2009-07-22 11:39:59.000000000 +0900
@@ -74,6 +74,12 @@
   end
 
   module BDBExtension
+    def copies(val)
+      duplicates val, false
+    rescue
+      duplicates val
+    end
+
     def each_by_prefix(prefix)
       values = []
       cursor = self.cursor
