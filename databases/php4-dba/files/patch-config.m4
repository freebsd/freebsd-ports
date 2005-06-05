--- config.m4.orig	Sat Sep 25 23:32:20 2004
+++ config.m4	Wed Jan 12 23:42:24 2005
@@ -206,6 +206,18 @@
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
@@ -224,7 +236,7 @@
         break
       fi
     done
-    PHP_DBA_DB_CHECK(4, db-4.2 db-4.1 db-4.0 db-4 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
+    PHP_DBA_DB_CHECK(4, db-4.3 db-4.2 db-4.1 db-4.0 db-4 db41 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
   fi
 ])
 AC_DBA_STD_RESULT(db4,Berkeley DB4)
