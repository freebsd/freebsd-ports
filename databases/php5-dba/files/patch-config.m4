--- config.m4.orig	2012-11-21 06:12:20.000000000 +0100
+++ config.m4	2012-12-12 10:18:42.000000000 +0100
@@ -320,6 +320,38 @@
       THIS_PREFIX=$i
       THIS_INCLUDE=$i/db4/db.h
       break
+    elif test -f "$i/include/db5/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db5/db.h
+      break
+    elif test -f "$i/include/db48/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db48/db.h
+      break
+    elif test -f "$i/include/db47/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db47/db.h
+      break
+    elif test -f "$i/include/db46/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db46/db.h
+      break
+    elif test -f "$i/include/db44/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db44/db.h
+      break
+    elif test -f "$i/include/db43/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db43/db.h
+      break
+    elif test -f "$i/include/db42/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db42/db.h
+      break
+    elif test -f "$i/include/db41/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db41/db.h
+      break
     elif test -f "$i/include/db5.1/db.h"; then
       THIS_PREFIX=$i
       THIS_INCLUDE=$i/include/db5.1/db.h
@@ -362,7 +394,7 @@
       break
     fi
   done
-  PHP_DBA_DB_CHECK(4, db-5.1 db-5.0 db-4.8 db-4.7 db-4.6 db-4.5 db-4.4 db-4.3 db-4.2 db-4.1 db-4.0 db-4 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
+  PHP_DBA_DB_CHECK(4, db-5 db-5.1 db-5.0 db-4.8 db-4.7 db-4.6 db-4.5 db-4.4 db-4.3 db-4.2 db-4.1 db-4.0 db-4 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
 fi
 PHP_DBA_STD_RESULT(db4,Berkeley DB4)
 
