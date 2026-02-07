--- villa/extconf.rb.orig	2006-01-17 08:27:10 UTC
+++ villa/extconf.rb
@@ -2,17 +2,15 @@ require 'mkmf'
 
 dir_config("villa")
 
-home = ENV['HOME']
-$CFLAGS = "-I. -I../.. -I#{home}/include -I/usr/local/include"
-$LDFLAGS = "-L../.. -L#{home}/lib -L/usr/local/lib"
-$LIBS = "-L../.. -L#{home}/lib -L/usr/local/lib"
+$CFLAGS = ENV['CFLAGS']
+$LDFLAGS = ENV['LDFLAGS']
+$LIBS = ENV['LIBS']
 
 have_library("c", "main")
 have_library("pthread", "main")
 have_library("z", "main")
 have_library("bz2", "main")
 have_library("lzo2", "main")
-have_library("iconv", "main")
 have_library("qdbm", "main")
 
 create_makefile("mod_villa")
