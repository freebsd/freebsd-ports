--- config.m4.orig	2024-09-10 16:10:06 UTC
+++ config.m4
@@ -433,6 +433,14 @@ if test "$PHP_DB4" != "no"; then
       THIS_PREFIX=$i
       THIS_INCLUDE=$i/include/db5.3/db.h
       break
+    elif test -f "$i/include/db5/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db5/db.h
+      break
+    elif test -f "$i/include/db18/db.h"; then
+      THIS_PREFIX=$i
+      THIS_INCLUDE=$i/include/db18/db.h
+      break
     elif test -f "$i/include/db5.1/db.h"; then
       THIS_PREFIX=$i
       THIS_INCLUDE=$i/include/db5.1/db.h
@@ -480,6 +488,7 @@ if test "$PHP_DB4" != "no"; then
       db-5.3
       db-5.1
       db-5.0
+      db-5
       db-4.8
       db-4.7
       db-4.6
