--- extconf.rb~	Sun May  5 03:16:11 2002
+++ extconf.rb	Sat Dec  7 09:30:02 2002
@@ -2,8 +2,8 @@
 
 xmms_config = with_config("xmms-config", "xmms-config")
 
-$CFLAGS << ' ' << `#{xmms_config} --cflags`.chomp
-$LDFLAGS << ' ' << `#{xmms_config} --libs`.chomp
+$CFLAGS << ' ' << ENV["CFLAGS"] << ' ' << `#{xmms_config} --cflags`.chomp
+$LDFLAGS << ' ' << ENV["LDFLAGS"] << ' ' << `#{xmms_config} --libs`.chomp
 
 have_library("xmms", "xmms_remote_get_version") and
   create_makefile("xmms")
