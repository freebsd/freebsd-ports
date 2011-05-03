--- install.rb.orig	2011-04-18 19:15:14.000000000 +0100
+++ install.rb	2011-04-18 19:15:34.000000000 +0100
@@ -83,7 +83,7 @@
 opts = OptionParser.new do |o|
   o.program_name = "ruby install.rb"
   o.separator "Options:"
-  o.on('--doc-base DIR', '-d', "Install documentation to DIR/stdlib") { |@doc_base| }
+  o.on('--doc-base DIR', '-d', "Install documentation to DIR/stdlib") { |_doc_base| @doc_base = _doc_base}
   o.on('--force', '-f', "Don't ask any questions; just install") { @force = true }
   o.on('--interactive', '-i', "Confirm any risky actions") { @force = false }
   o.on_tail('--help', '-h', "Show this message") do
