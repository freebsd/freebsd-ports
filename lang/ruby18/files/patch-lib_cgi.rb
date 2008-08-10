--- lib/cgi.rb.orig	2008-08-10 14:28:28.000000000 +0400
+++ lib/cgi.rb	2008-08-10 14:28:44.000000000 +0400
@@ -1032,13 +1032,13 @@
           if "--" == $2
             content_length = -1
           end
-         boundary_end = $2.dup
+          boundary_end = $2.dup
           ""
         end
 
         body.rewind
 
-        /Content-Disposition:.* filename=(?:"((?:\\.|[^\"])*)"|([^;]*))/ni.match(head)
+        /Content-Disposition:.* filename=(?:"((?:\\.|[^\"])*)"|([^;\s]*))/ni.match(head)
 	filename = ($1 or $2 or "")
 	if /Mac/ni.match(env_table['HTTP_USER_AGENT']) and
 	    /Mozilla/ni.match(env_table['HTTP_USER_AGENT']) and
@@ -1046,7 +1046,7 @@
 	  filename = CGI::unescape(filename)
 	end
         
-        /Content-Type: (.*)/ni.match(head)
+        /Content-Type: ([^\s]*)/ni.match(head)
         content_type = ($1 or "")
 
         (class << body; self; end).class_eval do
@@ -1055,7 +1055,7 @@
           define_method(:content_type) {content_type.dup.taint}
         end
 
-        /Content-Disposition:.* name="?([^\";]*)"?/ni.match(head)
+        /Content-Disposition:.* name="?([^\";\s]*)"?/ni.match(head)
         name = $1.dup
 
         if params.has_key?(name)
