--- mkmf_gimp.rb.orig	Thu Mar 15 00:55:02 2001
+++ mkmf_gimp.rb	Sun Mar 18 04:54:48 2001
@@ -22,25 +22,10 @@
   else
     config_cmds = "#{CONFIG['RUBY_INSTALL_NAME']} ../gimp-config.mingw"
   end
-  if ARGV.size > 0
-    config_cmds = ARGV.shift
-  end
+
+  config_cmds = with_config("gimp-config", config_cmds)
 
   CFLAGS  = `#{config_cmds} --cflags`.chomp
   LDFLAGS = `#{config_cmds} --libs`.chomp
-
-  if /win32|mingw/ =~ RUBY_PLATFORM
-    LIBGLIB   = "glib-1.3"
-    LIBGDK    = "gdk-1.3"
-    LIBGTK    = "gtk-1.3"
-    LIBGIMP   = "gimp-1.2"
-    LIBGIMPUI = "gimpui-1.2"
-  else
-    LIBGLIB   = "glib"
-    LIBGDK    = "gdk"
-    LIBGTK    = "gtk"
-    LIBGIMP   = "gimp"
-    LIBGIMPUI = "gimpui"
-  end
 
 end
