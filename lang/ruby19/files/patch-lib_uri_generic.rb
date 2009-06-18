--- lib/uri/generic.rb.orig	2009-06-18 16:47:45.000000000 +0400
+++ lib/uri/generic.rb	2009-06-18 16:48:54.000000000 +0400
@@ -1032,7 +1032,15 @@
           end
         end
 
-        str << path_query
+        path = path_query
+
+        #
+        # Add URI delimiter if the path misses it (like as in FTP)
+        #
+        if not path.empty? and not str.empty? and path[0, 1] != '/'
+          path = '/' + path 
+        end
+        str << path
       end
 
       if @fragment
