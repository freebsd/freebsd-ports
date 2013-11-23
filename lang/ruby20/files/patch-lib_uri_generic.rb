--- lib/uri/generic.rb.orig	2012-07-20 01:56:21.000000000 +0000
+++ lib/uri/generic.rb	2013-11-21 20:50:14.143925606 +0000
@@ -1482,6 +1482,17 @@
         end
 
         str << path_query
+        path = path_query
+
+        #
+        # Add URI delimiter if the path misses it (like as in FTP)
+        #
+        if not path.empty? and not str.empty? and path[0, 1] != '/'
+          path = '/' + path
+        end
+        str << path
+       end 
+       if @fragment
       end
 
       if @fragment
