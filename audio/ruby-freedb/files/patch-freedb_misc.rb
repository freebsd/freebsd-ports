--- lib/freedb_misc.rb.orig	Sun Apr  7 22:40:20 2002
+++ lib/freedb_misc.rb	Fri Aug 30 19:58:47 2002
@@ -4,12 +4,12 @@
 class Freedb
   VERSION = "0.3"
   PROTO_LEVEL = 1
-  attr_reader :results, :artist, :title, :tracks, :discid
+  attr_reader :results, :genre, :artist, :title, :tracks, :discid
   
   def initialize(param = "/dev/cdrom", is_discid = false)
     @discid = ( is_discid ? param : get_cdrom(param) )
     @tracks = Array.new()
-    @hello_str="#{ENV["USER"]} #{`hostname`.strip} ruby-freedb #{VERSION}"
+    @hello_str="#{ENV['USER']} #{`hostname`.strip} ruby-freedb #{VERSION}"
   end
 
   def fetch_net(server = "freedb.org", port = 8880)
@@ -29,6 +29,8 @@
     lines = getmultiline(@handler)
     lines.each { |line|
       case line
+	when /^210 (\S+)/
+	  @genre = $1
         when /^DTITLE=/
 	  md = /DTITLE=(.*) \/ (.*)/.match(line)
 	  if md.nil? #the DTITLE field is wrong.Should we throw an exception?
