--- extconf.rb.orig	Wed May 12 19:19:36 1999
+++ extconf.rb	Fri Nov  9 10:14:03 2001
@@ -1,5 +1,19 @@
 require 'mkmf'
+INTERBASEDIR = "/usr/interbase"
 
-have_library("gdslib", "isc_attach_database") or
-  have_library("gds", "isc_attach_database")
+incdir = with_config("interbase-include-dir")
+if incdir then
+  $CFLAGS += " -I#{incdir}"
+else
+  $CFLAGS = " -I#{INTERBASEDIR}/include"
+end
+
+libdir = with_config("interbase-lib-dir")
+if libdir then
+  $LDFLAGS += "-L#{libdir}"
+else
+  $LDFLAGS = "-L#{INTERBASEDIR}/lib"
+end
+
+$libs = "-lgds"
 create_makefile("interbase")
