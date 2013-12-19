--- cmakemodules/FindBDB.cmake.orig	2013-10-20 19:33:20.000000000 -0500
+++ cmakemodules/FindBDB.cmake	2013-12-07 20:44:12.000000000 -0500
@@ -5,6 +5,7 @@
 FIND_PATH(BDB_INCLUDE_DIR db.h NO_DEFAULT_PATH PATHS
   "/usr/local/BerkeleyDB.6.0/include"
   "/usr/local/BerkeleyDB.5.3/include"
+  "/usr/local/include/db5"
   "${BDB_PREFIX}/include"
 ) 
 else()
@@ -37,6 +38,7 @@
   #OSX (and probably other unix) src build
   "/usr/local/BerkeleyDB.6.0/lib"
   "/usr/local/BerkeleyDB.5.3/lib"
+  "/usr/local/lib/db5"
   "${BDB_PREFIX}/lib"
   "${BDB_PREFIX}"
 )
