--- cmakemodules/FindBDB.cmake.orig	2013-06-23 17:20:25.000000000 -0700
+++ cmakemodules/FindBDB.cmake	2013-06-23 17:24:59.000000000 -0700
@@ -4,6 +4,7 @@
 if(APPLE) #exclude obsolete default OSX db
 FIND_PATH(BDB_INCLUDE_DIR db.h NO_DEFAULT_PATH PATHS
   "/usr/local/BerkeleyDB.5.3/include"
+  "/usr/local/include/db5"
   "${BDB_PREFIX}/include"
 ) 
 else()
@@ -26,6 +27,7 @@
   "C:\\db-5.3.21\\build_windows\\Win32\\Static_Release\\" #vc08 adds underscore
   #OSX (and probably other unix) src build
   "/usr/local/BerkeleyDB.5.3/lib"
+  "/usr/local/lib/db5"
   "${BDB_PREFIX}/lib"
 )
 MARK_AS_ADVANCED(BDB_LIBRARY)
