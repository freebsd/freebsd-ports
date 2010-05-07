--- ./apr-util-1.3.9/build/dbm.m4.orig	2008-11-21 01:32:58.000000000 -0500
+++ ./apr-util-1.3.9/build/dbm.m4	2010-05-06 20:21:58.910611623 -0400
@@ -522,6 +522,25 @@
     apu_db_version=4
   fi
 ])
+dnl
+dnl APU_CHECK_DB48: is DB4.8 present?
+dnl
+dnl if present: sets apu_db_header, apu_db_lib, and apu_db_version
+dnl
+AC_DEFUN([APU_CHECK_DB48], [
+  places=$1
+  if test -z "$places"; then
+    places="std /usr/local/BerkeleyDB.4.8 /boot/home/config"
+  fi
+  APU_CHECK_BERKELEY_DB("4", "8", "-1",
+    "$places",
+    "db48/db.h db4/db.h db.h",
+    "db-4.8 db4-4.8 db48 db4 db"
+  )
+  if test "$apu_have_db" = "1"; then
+    apu_db_version=4
+  fi
+])
 
 AC_DEFUN([APU_CHECK_DB], [
   requested=$1
@@ -606,6 +625,12 @@
       AC_MSG_ERROR(Berkeley db4 not found)
     fi
     ;;
+  db48)
+    APU_CHECK_DB48("$check_places")
+    if test "$apu_db_version" != "4"; then
+      AC_MSG_ERROR(Berkeley db4 not found)
+    fi
+    ;;
   default)
     APU_CHECK_DB_ALL("$check_places")
     ;;
@@ -613,34 +638,37 @@
 ])
 
 dnl
-dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 4.7 to 1.
+dnl APU_CHECK_DB_ALL: Try all Berkeley DB versions, from 4.8 to 1.
 dnl
 AC_DEFUN([APU_CHECK_DB_ALL], [
   all_places=$1
  
-  APU_CHECK_DB47("$all_places")
+  APU_CHECK_DB48("$all_places")
   if test "$apu_db_version" != "4"; then
-    APU_CHECK_DB46("$all_places")
+    APU_CHECK_DB47("$all_places")
     if test "$apu_db_version" != "4"; then
-      APU_CHECK_DB45("$all_places")
+      APU_CHECK_DB46("$all_places")
       if test "$apu_db_version" != "4"; then
-        APU_CHECK_DB44("$all_places")
+        APU_CHECK_DB45("$all_places")
         if test "$apu_db_version" != "4"; then
-          APU_CHECK_DB43("$all_places")
+          APU_CHECK_DB44("$all_places")
           if test "$apu_db_version" != "4"; then
-            APU_CHECK_DB42("$all_places")
+            APU_CHECK_DB43("$all_places")
             if test "$apu_db_version" != "4"; then
-              APU_CHECK_DB41("$all_places")
+              APU_CHECK_DB42("$all_places")
               if test "$apu_db_version" != "4"; then
-                APU_CHECK_DB4("$all_places")
+                APU_CHECK_DB41("$all_places")
                 if test "$apu_db_version" != "4"; then
-                  APU_CHECK_DB3("$all_places")
-                  if test "$apu_db_version" != "3"; then
-                    APU_CHECK_DB2("$all_places")
-                    if test "$apu_db_version" != "2"; then
-                      APU_CHECK_DB1("$all_places")
-                      if test "$apu_db_version" != "1"; then
-                        APU_CHECK_DB185("$all_places")
+                  APU_CHECK_DB4("$all_places")
+                  if test "$apu_db_version" != "4"; then
+                    APU_CHECK_DB3("$all_places")
+                    if test "$apu_db_version" != "3"; then
+                      APU_CHECK_DB2("$all_places")
+                      if test "$apu_db_version" != "2"; then
+                        APU_CHECK_DB1("$all_places")
+                        if test "$apu_db_version" != "1"; then
+                          APU_CHECK_DB185("$all_places")
+                        fi
                       fi
                     fi
                   fi
@@ -679,11 +707,11 @@
   apu_db_version=0
 
   AC_ARG_WITH(dbm, [APR_HELP_STRING([--with-dbm=DBM], [choose the DBM type to use.
-      DBM={sdbm,gdbm,ndbm,db,db1,db185,db2,db3,db4,db41,db42,db43,db44,db45,db46,db47}])],
+      DBM={sdbm,gdbm,ndbm,db,db1,db185,db2,db3,db4,db41,db42,db43,db44,db45,db46,db47,db48}])],
   [
     if test "$withval" = "yes"; then
       AC_MSG_ERROR([--with-dbm needs to specify a DBM type to use.
-        One of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46, db47])
+        One of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46, db47, db48])
     fi
     requested="$withval"
   ], [
@@ -882,6 +910,10 @@
       apu_use_db=1
       apu_default_dbm=db4
       ;;
+    db48)
+      apu_use_db=1
+      apu_default_dbm=db4
+      ;;
     default)
       dnl ### use more sophisticated DBMs for the default?
       apu_default_dbm="sdbm (default)"
@@ -889,7 +921,7 @@
       ;;
     *)
       AC_MSG_ERROR([--with-dbm=$look_for is an unknown DBM type.
-        Use one of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46, db47])
+        Use one of: sdbm, gdbm, ndbm, db, db1, db185, db2, db3, db4, db41, db42, db43, db44, db45, db46, db47, db48])
       ;;
   esac
 
