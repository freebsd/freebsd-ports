--- extconf.rb.orig	Tue Oct 16 07:27:04 2001
+++ extconf.rb	Sat Oct 20 20:28:04 2001
@@ -1,13 +1,17 @@
 #!/usr/bin/ruby -w
 require 'mkmf'
-puts "GTK+ version: #{`gtk-config --version`}"
-puts "GConf version: #{`gconf-config --version`}"
-$CFLAGS << ' -O3 -Wall '
-$CFLAGS << `gconf-config --cflags`.chomp
+
+gconf_config = with_config('gconf-config', 'gconf-config')
+gtk_config = with_config('gtk-config', 'gtk-config')
+
+puts "GTK+ version: #{`#{gtk_config} --version`}"
+puts "GConf version: #{`#{gconf_config} --version`}"
+$CFLAGS << ' -Wall '
+$CFLAGS << `#{gconf_config} --cflags`.chomp
 $CFLAGS << ' '
-$CFLAGS << `gtk-config --cflags`
-$LDFLAGS << `gconf-config --libs`.chomp
+$CFLAGS << `#{gtk_config} --cflags`
+$LDFLAGS << `#{gconf_config} --libs`.chomp
 $LDFLAGS << ' -lgconf-gtk-1 '
-$LDFLAGS << `gtk-config --libs`
+$LDFLAGS << `#{gtk_config} --libs`
 Dir.chdir('src')
 create_makefile('gconf')
