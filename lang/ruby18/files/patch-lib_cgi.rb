--- lib/cgi.rb.orig	Tue Aug 22 13:38:19 2006
+++ lib/cgi.rb	Mon Dec  4 23:22:42 2006
@@ -967,6 +967,7 @@
     def read_multipart(boundary, content_length)
       params = Hash.new([])
       boundary = "--" + boundary
+      quoted_boundary = Regexp.quote(boundary, "n")
       buf = ""
       bufsize = 10 * 1024
       boundary_end=""
@@ -998,7 +999,7 @@
         end
         body.binmode if defined? body.binmode
 
-        until head and /#{boundary}(?:#{EOL}|--)/n.match(buf)
+        until head and /#{quoted_boundary}(?:#{EOL}|--)/n.match(buf)
 
           if (not head) and /#{EOL}#{EOL}/n.match(buf)
             buf = buf.sub(/\A((?:.|\n)*?#{EOL})#{EOL}/n) do
@@ -1018,14 +1019,14 @@
               else
                 stdinput.read(content_length)
               end
-          if c.nil?
+          if c.nil? || c.empty?
             raise EOFError, "bad content body"
           end
           buf.concat(c)
           content_length -= c.size
         end
 
-        buf = buf.sub(/\A((?:.|\n)*?)(?:[\r\n]{1,2})?#{boundary}([\r\n]{1,2}|--)/n) do
+        buf = buf.sub(/\A((?:.|\n)*?)(?:[\r\n]{1,2})?#{quoted_boundary}([\r\n]{1,2}|--)/n) do
           body.print $1
           if "--" == $2
             content_length = -1
