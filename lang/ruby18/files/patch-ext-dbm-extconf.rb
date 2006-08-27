--- ext/dbm/extconf.rb.orig	Sat Aug 26 20:04:57 2006
+++ ext/dbm/extconf.rb	Sat Aug 26 21:48:20 2006
@@ -55,7 +55,7 @@
 
 have_header("cdefs.h") 
 have_header("sys/cdefs.h") 
-if /DBM_HDR/ =~ $CFLAGS and have_func(db_prefix("dbm_open"))
+if $defs.each { |d| /DBM_HDR/ =~ d } and have_func(db_prefix("dbm_open"))
   have_func(db_prefix("dbm_clearerr")) unless $dbm_conf_have_gdbm
   create_makefile("dbm")
 end
