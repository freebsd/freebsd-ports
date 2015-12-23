--- cmakemodules/FindBDB.cmake.orig	2015-10-21 17:26:38 UTC
+++ cmakemodules/FindBDB.cmake
@@ -1,10 +1,12 @@
 # Find Berkeley DB
 
 # Look for the header file.
-if(APPLE) #exclude obsolete default OSX db
+if(APPLE OR CMAKE_HOST_SYSTEM_NAME STREQUAL "FreeBSD") #exclude obsolete default OSX db
 FIND_PATH(BDB_INCLUDE_DIR db.h NO_DEFAULT_PATH PATHS
   "/usr/local/BerkeleyDB.6.0/include"
   "/usr/local/BerkeleyDB.5.3/include"
+  "/usr/local/include/db5"
+  "${BDB_PREFIX}/include/db5"
   "${BDB_PREFIX}/include"
 ) 
 else()
@@ -15,6 +17,8 @@ FIND_PATH(BDB_INCLUDE_DIR db.h
   "C:\\db-6.0.20\\build_windows"
   "C:\\db-6.0.20\\build_windows"
   "C:\\db-5.3.21\\build_windows"
+  #*nix dirs
+  "${BDB_PREFIX}/include"
 )
 endif()
 MARK_AS_ADVANCED(BDB_INCLUDE_DIR)
@@ -31,6 +35,7 @@ FIND_LIBRARY(BDB_LIBRARY NAMES 
   libdb6-0.3
   libdb6-0.so
   libdb_small53s
+  libdb5
   libdb53s
   libdb5-5.3
   libdb5-5.so
@@ -45,6 +50,7 @@ FIND_LIBRARY(BDB_LIBRARY NAMES 
   "/usr/local/BerkeleyDB.6.0/lib"
   "/usr/local/BerkeleyDB.5.3/lib"
   "${BDB_PREFIX}/lib"
+  "${BDB_PREFIX}/lib/db5"
   "${BDB_PREFIX}"
 )
 MARK_AS_ADVANCED(BDB_LIBRARY)
