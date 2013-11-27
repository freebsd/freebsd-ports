--- lib/uri/generic.rb.orig	2013-11-27 04:27:22.851503866 +0000
+++ lib/uri/generic.rb	2013-11-27 04:27:58.130502926 +0000
@@ -1481,7 +1481,17 @@
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
+       end 
+       if @fragment
       end
 
       if @fragment
