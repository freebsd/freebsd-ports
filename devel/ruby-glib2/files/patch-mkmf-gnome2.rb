--- src/lib/mkmf-gnome2.rb.orig	Sun Sep  7 21:00:32 2003
+++ src/lib/mkmf-gnome2.rb	Sat Oct 18 19:41:58 2003
@@ -137,11 +137,7 @@
   end
 end
 
-alias :old_create_makefile :create_makefile
-def create_makefile(lib, src_prefix = nil)
-  $CFLAGS << " -I$(sitearchdir) "
-  old_create_makefile(lib, src_prefix)
-end
+$CPPFLAGS << " -I$(sitearchdir) "
 
 def create_top_makefile(sub_dirs = ["src"])
   mfile = File.open("Makefile", "w")
