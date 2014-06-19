--- cmakemodules/FindBDB.cmake.orig	2014-05-08 17:59:25.000000000 -0700
+++ cmakemodules/FindBDB.cmake	2014-05-24 01:29:11.000000000 -0700
@@ -6,6 +6,7 @@
   "/usr/local/BerkeleyDB.6.0/include"
   "/usr/local/BerkeleyDB.5.3/include"
   "${BDB_PREFIX}/include"
+  "${BDB_PREFIX}/include/db5"
 ) 
 else()
 FIND_PATH(BDB_INCLUDE_DIR db.h
@@ -29,6 +30,7 @@
   libdb53s
   libdb5-5.3
   libdb5-5.so
+  libdb5
   PATHS
   "C:\\db-6.0.20\\build_windows\\Win32\\Static Release\\"
   "C:\\db-6.0.20\\build_windows\\Win32\\Static_Release\\" #vc08 adds underscore
@@ -38,6 +40,7 @@
   "/usr/local/BerkeleyDB.6.0/lib"
   "/usr/local/BerkeleyDB.5.3/lib"
   "${BDB_PREFIX}/lib"
+  "${BDB_PREFIX}/lib/db5"
   "${BDB_PREFIX}"
 )
 MARK_AS_ADVANCED(BDB_LIBRARY)
