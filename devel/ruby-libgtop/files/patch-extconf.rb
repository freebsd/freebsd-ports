--- extconf.rb.orig	Fri Apr 13 04:03:18 2001
+++ extconf.rb	Fri Apr 13 14:57:42 2001
@@ -34,12 +34,10 @@
 ######################################################################
 require "mkmf"
 
-dir_config("ruby_libgtop")
-have_library("gtop", nil)
-have_library("gtop_suid_common", nil)
-have_library("gtop_common", nil)
-have_library("gtop_names", nil)
-have_library("gtop_sysdeps", nil)
+libgtop_config = with_config("libgtop-config", "libgtop-config")
+
+$CFLAGS = `#{libgtop_config} --cflags`.chomp
+$LDFLAGS = `#{libgtop_config} --libs`.chomp
 
 create_makefile("ruby_libgtop")
 
