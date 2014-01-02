--- ./lib/rdoc/ruby_lex.rb.orig	2012-12-18 07:31:36.000000000 +0000
+++ ./lib/rdoc/ruby_lex.rb	2014-01-02 01:09:06.630327388 +0000
@@ -1028,6 +1028,8 @@
     end
 
     if output_heredoc then
+      raise Error, "Missing terminating #{quoted} for string" unless l
+
       doc << l.chomp
     else
       doc << '"'
