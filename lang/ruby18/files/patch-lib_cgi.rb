--- lib/cgi.rb.orig	Mon Mar 12 20:55:03 2007
+++ lib/cgi.rb	Wed May 23 01:58:09 2007
@@ -1163,6 +1163,7 @@
     # retrieved; use #params() to get the array of values.
     def [](key)
       params = @params[key]
+      return '' unless params
       value = params[0]
       if @multipart
         if value
