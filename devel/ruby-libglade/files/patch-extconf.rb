--- extconf.rb.orig	Wed Dec 12 10:24:28 2001
+++ extconf.rb	Wed Mar 20 21:25:58 2002
@@ -9,24 +9,16 @@
 #
 # detect libglade configurations
 #
-config_cmds = ["libglade-config"]
+config_cmd = with_config("libglade-config", "libglade-config")
 while /^--/ =~ ARGV[0]
   ARGV.shift
 end
-if ARGV.size > 0
-  config_cmds.unshift(ARGV[0])
-end
 
 begin
-  config_cmds.each do |config_cmd|
-    version = `#{config_cmd} --version`
-    if not version.chomp.empty?
-      config_libs, config_cflags = "--libs", "--cflags"
-      $LDFLAGS, *libs = `#{config_cmd} #{config_libs}`.chomp.split(/(-l.*)/)
-      $libs = libs.join(' ') + ' ' + $libs
-      $CFLAGS = `#{config_cmd} #{config_cflags}`.chomp
-      break
-    end
+  version = `#{config_cmd} --version`
+  if not version.chomp.empty?
+    $CFLAGS += ' ' + `#{config_cmd} --cflags`.chomp
+    $LDFLAGS += ' ' + `#{config_cmd} --libs`.chomp
   end
 rescue
   $LDFLAGS = '-L/usr/X11R6/lib -L/usr/local/lib'
