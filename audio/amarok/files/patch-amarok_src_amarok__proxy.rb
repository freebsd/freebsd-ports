
$FreeBSD$

--- amarok/src/amarok_proxy.rb.orig
+++ amarok/src/amarok_proxy.rb
@@ -117,6 +117,11 @@
   def cp_to_empty_outward( income, output )
     myputs "cp_to_empty_outward( income => #{income.inspect}, output => #{output.inspect}"
     income.each_line do |data|
+      if data =~ /User-Agent: xine\/([0-9.]+)/
+        version = $1.split(".").collect { |v| v.to_i }
+        myputs("Found xine user agent version #{version.join(".")}")
+        @xineworkaround = ( version[0] <= 1 && version[1] <= 1 && version[2] <= 2 )
+      end
       myputs( data )
       data.chomp!
       safe_write( output, data )
@@ -142,7 +147,7 @@
 
   def cp_all_inward( income, output )
     myputs( "cp_all( income => #{income.inspect}, output => #{output.inspect}" )
-    if self.is_a?( LastFM ) and @engine == 'xine-engine'
+    if self.is_a?( LastFM ) and @xineworkaround
       myputs( "Using buffer fill workaround." )
       filler = Array.new( 4096, 0 )
       safe_write( output, filler ) # HACK: Fill xine's buffer so that xine_open() won't block
