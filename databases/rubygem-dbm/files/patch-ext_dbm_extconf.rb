--- ext/dbm/extconf.rb.orig	2022-12-07 02:13:27 UTC
+++ ext/dbm/extconf.rb
@@ -7,6 +7,7 @@
 #   db          Berkeley DB (libdb)
 #   db2         Berkeley DB (libdb2)
 #   db1         Berkeley DB (libdb1)
+#   db18        Berkeley DB (libdb18)
 #   db6         Berkeley DB (libdb6)
 #   db5         Berkeley DB (libdb5)
 #   db4         Berkeley DB (libdb4)
@@ -24,7 +25,7 @@ dir_config("dbm")
 if dblib = with_config("dbm-type", nil)
   dblib = dblib.split(/[ ,]+/)
 else
-  dblib = %w(libc db db2 db1 db6 db5 db4 db3 gdbm_compat gdbm qdbm)
+  dblib = %w(libc db db2 db1 db18 db6 db5 db4 db3 gdbm_compat gdbm qdbm)
 end
 
 headers = {
@@ -36,6 +37,7 @@ headers = {
   "db4" => ["db4/db.h", "db4.h", "db.h"],
   "db5" => ["db5/db.h", "db5.h", "db.h"],
   "db6" => ["db6/db.h", "db6.h", "db.h"],
+  "db18" => ["db18/db.h", "db18.h", "db.h"],
   "gdbm_compat" => ["gdbm-ndbm.h", "gdbm/ndbm.h", "ndbm.h"], # GDBM since 1.8.1
   "gdbm" => ["gdbm-ndbm.h", "gdbm/ndbm.h", "ndbm.h"], # GDBM until 1.8.0
   "qdbm" => ["qdbm/relic.h", "relic.h"],
@@ -127,13 +129,27 @@ end
 
 
 def headers.db_check2(db, hdr)
+  libraries = {
+    "db" => "db",
+    "db1" => "db1",
+    "db2" => "db2",
+    "db3" => "db3",
+    "db4" => "db4",
+    "db5" => "db-5",
+    "db6" => "db-6",
+    "db18" => "db-18",
+    "gdbm_compat" => "gdbm_compat",
+    "gdbm" => "gdbm",
+    "qdbm" => "qdbm",
+  }
+
   $defs.push(%{-DRUBYDBM_DBM_HEADER='"#{hdr}"'})
   $defs.push(%{-DRUBYDBM_DBM_TYPE='"#{db}"'})
 
   hsearch = nil
 
   case db
-  when /^db[2-6]?$/
+  when /^db([2-6]|18)?$/
     hsearch = "-DDB_DBM_HSEARCH"
   when "gdbm_compat"
     have_library("gdbm") or return false
@@ -147,7 +163,7 @@ def headers.db_check2(db, hdr)
   # 4.3BSD original ndbm is contained in libc.
   # 4.4BSD (and its derivatives such as NetBSD) contains Berkeley DB 1 in libc.
   if !(db == 'libc' ? have_func('dbm_open("", 0, 0)', hdr, hsearch) :
-                      have_library(db, 'dbm_open("", 0, 0)', hdr, hsearch))
+                      have_library(libraries[db], 'dbm_open("", 0, 0)', hdr, hsearch))
     return false
   end
 
