--- config.m4.orig	Sat Jan 22 02:36:56 2005
+++ config.m4	Tue Jun 14 16:43:06 2005
@@ -240,6 +240,18 @@
         THIS_PREFIX=$i
         THIS_INCLUDE=$i/db4/db.h
         break
+      elif test -f "$i/include/db43/db.h"; then
+        THIS_PREFIX=$i
+        THIS_INCLUDE=$i/include/db43/db.h
+        break
+      elif test -f "$i/include/db42/db.h"; then
+        THIS_PREFIX=$i
+        THIS_INCLUDE=$i/include/db42/db.h
+        break
+      elif test -f "$i/include/db41/db.h"; then
+        THIS_PREFIX=$i
+        THIS_INCLUDE=$i/include/db41/db.h
+        break
       elif test -f "$i/include/db4/db.h"; then
         THIS_PREFIX=$i
         THIS_INCLUDE=$i/include/db4/db.h
@@ -258,7 +270,7 @@
         break
       fi
     done
-    PHP_DBA_DB_CHECK(4, db-4.2 db-4.1 db-4.0 db-4 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
+    PHP_DBA_DB_CHECK(4, db-4.3 db-4.2 db-4.1 db-4.0 db-4 db41 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
   fi
 ])
 AC_DBA_STD_RESULT(db4,Berkeley DB4)
