--- config.m4.orig	Tue Nov 28 12:41:35 2006
+++ config.m4	Sat Feb 17 11:13:51 2007
@@ -205,6 +205,22 @@
         THIS_PREFIX=$i
         THIS_INCLUDE=$i/db4/db.h
         break
+      elif test -f "$i/include/db44/db.h"; then
+        THIS_PREFIX=$i
+        THIS_INCLUDE=$i/include/db44/db.h
+        break
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
@@ -223,7 +239,7 @@
         break
       fi
     done
-    PHP_DBA_DB_CHECK(4, db-4.5 db-4.4 db-4.3 db-4.2 db-4.1 db-4.0 db-4 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
+    PHP_DBA_DB_CHECK(4, db-4.5 db-4.4 db-4.3 db-4.2 db-4.1 db-4.0 db-4 db41 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
   fi
 ])
 AC_DBA_STD_RESULT(db4,Berkeley DB4)
