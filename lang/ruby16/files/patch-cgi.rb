--- lib/cgi.rb	2002/08/25 20:15:54	1.23.2.17
+++ lib/cgi.rb	2004/10/24 23:37:19	1.23.2.18
@@ -182,7 +182,7 @@ class CGI
   CR  = "\015"
   LF  = "\012"
   EOL = CR + LF
-  REVISION = '$Id: cgi.rb,v 1.23.2.17 2002/08/25 20:15:54 wakou Exp $'
+  REVISION = '$Id: cgi.rb,v 1.23.2.18 2004/10/24 23:37:19 matz Exp $'
 
   NEEDS_BINMODE = true if /WIN/ni.match(RUBY_PLATFORM)
   PATH_SEPARATOR = {'UNIX'=>'/', 'WINDOWS'=>'\\', 'MACINTOSH'=>':'}
@@ -823,13 +823,15 @@     def read_multipart(boundary, content
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
           buf += c
           content_length -= c.size
-
         end
 
         buf = buf.sub(/\A((?:.|\n)*?)(?:#{EOL})?#{boundary}(#{EOL}|--)/n) do
