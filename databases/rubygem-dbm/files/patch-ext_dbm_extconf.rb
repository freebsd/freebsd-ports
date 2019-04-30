--- ext/dbm/extconf.rb.orig	2018-08-01 14:46:21 UTC
+++ ext/dbm/extconf.rb
@@ -23,7 +23,7 @@ dir_config("dbm")
 if dblib = with_config("dbm-type", nil)
   dblib = dblib.split(/[ ,]+/)
 else
-  dblib = %w(libc db db2 db1 db5 db4 db3 gdbm_compat gdbm qdbm)
+  dblib = %w(libc db db2 db1 db6 db5 db48 db3 gdbm_compat gdbm qdbm)
 end
 
 headers = {
@@ -32,8 +32,9 @@ headers = {
   "db1" => ["db1/ndbm.h", "db1.h", "ndbm.h"],
   "db2" => ["db2/db.h", "db2.h", "db.h"],
   "db3" => ["db3/db.h", "db3.h", "db.h"],
-  "db4" => ["db4/db.h", "db4.h", "db.h"],
+  "db48" => ["db48/db.h", "db4.h", "db.h"],
   "db5" => ["db5/db.h", "db5.h", "db.h"],
+  "db6" => ["db6/db.h", "db6.h", "db.h"],
   "gdbm_compat" => ["gdbm-ndbm.h", "gdbm/ndbm.h", "ndbm.h"], # GDBM since 1.8.1
   "gdbm" => ["gdbm-ndbm.h", "gdbm/ndbm.h", "ndbm.h"], # GDBM until 1.8.0
   "qdbm" => ["qdbm/relic.h", "relic.h"],
@@ -125,13 +126,26 @@ end
 
 
 def headers.db_check2(db, hdr)
+  libraries = {
+    "db" => "db",
+    "db1" => "db1",
+    "db2" => "db2",
+    "db3" => "db3",
+    "db48" => "db-4.8",
+    "db5" => "db-5",
+    "db6" => "db-6",
+    "gdbm_compat" => "gdbm_compat",
+    "gdbm" => "gdbm",
+    "qdbm" => "qdbm",
+  }
+
   $defs.push(%{-DRUBYDBM_DBM_HEADER='"#{hdr}"'})
   $defs.push(%{-DRUBYDBM_DBM_TYPE='"#{db}"'})
 
   hsearch = nil
 
   case db
-  when /^db[2-5]?$/
+  when /^db[2-6].*$/
     hsearch = "-DDB_DBM_HSEARCH"
   when "gdbm_compat"
     have_library("gdbm") or return false
@@ -145,7 +159,7 @@ def headers.db_check2(db, hdr)
   # 4.3BSD original ndbm is contained in libc.
   # 4.4BSD (and its derivatives such as NetBSD) contains Berkeley DB 1 in libc.
   if !(db == 'libc' ? have_func('dbm_open("", 0, 0)', hdr, hsearch) :
-                      have_library(db, 'dbm_open("", 0, 0)', hdr, hsearch))
+                      have_library(libraries[db], 'dbm_open("", 0, 0)', hdr, hsearch))
     return false
   end
 
