--- src/extconf.rb.orig	Thu Jun 13 17:12:48 2002
+++ src/extconf.rb	Fri Jan 24 04:21:24 2003
@@ -2,7 +2,7 @@
 # vim: ts=2 sw=2
 require 'mkmf'
 
-$CFLAGS << "-Wall `evas-config --cflags`"
-$LDFLAGS << `evas-config --libs`
+$CFLAGS << " -Wall `evas-config --cflags`"
+$LDFLAGS << ' ' << `evas-config --libs`.chomp
 
 create_makefile("evas")
