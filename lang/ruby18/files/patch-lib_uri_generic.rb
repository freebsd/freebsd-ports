--- lib/uri/generic.rb.orig	2009-06-18 16:10:22.000000000 +0400
+++ lib/uri/generic.rb	2009-06-18 16:10:51.000000000 +0400
@@ -1027,7 +1027,15 @@
           end
         end
 
-        str << path_query
+	path = path_query
+
+	#
+	# Add URI delimiter if the path misses it (like as in FTP)
+	#
+	if not path.empty? and not str.empty? and path[0, 1] != '/'
+	  path = '/' + path 
+	end
+        str << path
       end
 
       if @fragment
