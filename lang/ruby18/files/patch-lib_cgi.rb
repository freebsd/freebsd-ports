--- lib/cgi.rb      2005-10-06 19:01:22.000000000 -0600
+++ lib/cgi.rb      2006-09-22 16:38:08.000000000 -0600
@@ -1017,7 +1017,7 @@
               else
                 stdinput.read(content_length)
               end
-          if c.nil?
+          if c.nil? || c.empty?
             raise EOFError, "bad content body"
           end
           buf.concat(c)
