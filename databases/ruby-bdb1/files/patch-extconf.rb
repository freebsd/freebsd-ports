--- src/extconf.rb.orig	Mon Nov 26 22:35:33 2001
+++ src/extconf.rb	Wed Jan 16 07:00:46 2002
@@ -6,7 +6,9 @@
 end
 $CFLAGS += " -I#{incdir}" if incdir = with_config("db-include-dir")
 $LDFLAGS += " -I#{libdir}" if libdir = with_config("db-lib-dir")
-if !(have_library("db1", "__hash_open") || have_library("db", "__hash_open"))
+if !(have_func("__hash_open") || \
+     have_library("db1", "__hash_open") || \
+     have_library("db", "__hash_open"))
     raise "libdb.a not found"
 end
 create_makefile("bdb1")
