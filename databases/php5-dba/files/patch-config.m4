--- config.m4.orig	Mon Aug 22 21:59:36 2005
+++ config.m4	Thu Sep  8 10:48:31 2005
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
