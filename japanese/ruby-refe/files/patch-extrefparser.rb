--- lib/refe/extrefparser.rb.orig	Fri Mar 22 20:21:23 2002
+++ lib/refe/extrefparser.rb	Sun Nov 24 17:22:24 2002
@@ -39,7 +39,7 @@
       f.each do |line|
         next if /\A[=\w]/ === line
         if /\A: / === line then
-          m = /\A: .*?(\w+)\(/.match(line) or
+          m = /\A: .*?(\w+)(\(|$)/.match(line) or
                   raise "parse failed: #{line.inspect}"
           curr = line
           table[ m[1] ] = curr
