--- config.m4.orig	2007-12-06 15:17:43.000000000 +0100
+++ config.m4	2008-12-11 12:50:27.000000000 +0100
@@ -280,6 +280,34 @@
       THIS_PREFIX=$i
       THIS_INCLUDE=$i/db4/db.h
       break
+    elif test -f "$i/include/db47/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db47/db.h
+      break
+    elif test -f "$i/include/db46/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db46/db.h
+      break
+    elif test -f "$i/include/db45/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db45/db.h
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
     elif test -f "$i/include/db4.6/db.h"; then
       THIS_PREFIX=$i
       THIS_INCLUDE=$i/include/db4.6/db.h
@@ -306,7 +334,7 @@
       break
     fi
   done
-  PHP_DBA_DB_CHECK(4, db-4.6 db-4.5 db-4.4 db-4.3 db-4.2 db-4.1 db-4.0 db-4 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
+  PHP_DBA_DB_CHECK(4, db-4.7 db-4.6 db-4.5 db-4.4 db-4.3 db-4.2 db-4.1 db-4.0 db-4 db4 db, [(void)db_create((DB**)0, (DB_ENV*)0, 0)])
 fi
 PHP_DBA_STD_RESULT(db4,Berkeley DB4)
 
