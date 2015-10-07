--- ./lib/rdoc/ruby_lex.rb.orig	2012-12-18 07:31:36 UTC
+++ ./lib/rdoc/ruby_lex.rb
@@ -1028,6 +1028,8 @@
     end
 
     if output_heredoc then
+      raise Error, "Missing terminating #{quoted} for string" unless l
+
       doc << l.chomp
     else
       doc << '"'
