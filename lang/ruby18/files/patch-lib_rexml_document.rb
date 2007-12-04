--- lib/rexml/document.rb.orig	2007-12-04 03:05:22.000000000 +0300
+++ lib/rexml/document.rb	2007-12-04 03:05:26.000000000 +0300
@@ -183,7 +183,7 @@
         output = Output.new( output, xml_decl.encoding )
       end
       formatter = if indent > -1
-          if transitive
+          if trans
             REXML::Formatters::Transitive.new( indent, ie_hack )
           else
             REXML::Formatters::Pretty.new( indent, ie_hack )
