--- extconf.rb.orig	Wed Jan 29 08:59:59 2003
+++ extconf.rb	Wed Jan 29 19:02:41 2003
@@ -24,13 +24,18 @@
 else
   exit 1
 end
+$objs = ["mysql.o"]
 create_makefile("mysql")
 
 # make mysql constant
 File::open("conftest.c", "w") do |f|
   f.puts src
 end
-cpp = Config::expand sprintf(CPP, $CPPFLAGS, $CFLAGS, '')
+if defined? cpp_command
+  cpp = Config.expand(cpp_command(CONFIG['CPPOUTFILE']))
+else
+  cpp = Config::expand sprintf(CPP, $CPPFLAGS, $CFLAGS, '')
+end
 unless system "#{cpp} > confout" then
   exit 1
 end
