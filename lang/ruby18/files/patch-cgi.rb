--- lib/cgi.rb	2004/07/28 13:26:01	1.68.2.6
+++ lib/cgi.rb	2004/10/27 02:46:50	1.68.2.7
@@ -284,7 +284,7 @@ class CGI
   # Standard internet newline sequence
   EOL = CR + LF
 
-  REVISION = '$Id: cgi.rb,v 1.68.2.6 2004/07/28 13:26:01 matz Exp $' #:nodoc:
+  REVISION = '$Id: cgi.rb,v 1.68.2.7 2004/10/27 02:46:50 matz Exp $' #:nodoc:
 
   NEEDS_BINMODE = true if /WIN/ni.match(RUBY_PLATFORM) 
 
@@ -1012,10 +1012,13 @@     def read_multipart(boundary, content
           end
 
           c = if bufsize < content_length
-                stdinput.read(bufsize) or ''
+                stdinput.read(bufsize)
               else
-                stdinput.read(content_length) or ''
+                stdinput.read(content_length)
               end
+          if c.nil?
+            raise EOFError, "bad content body"
+          end
           buf.concat(c)
           content_length -= c.size
         end
