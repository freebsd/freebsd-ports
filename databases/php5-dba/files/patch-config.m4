--- config.m4.orig	Tue Dec  5 18:54:52 2006
+++ config.m4	Wed Feb  7 12:47:51 2007
@@ -244,6 +244,22 @@
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
@@ -493,7 +509,7 @@
     PHP_DBA_STD_ATTACH
   fi
 ],[
-  if test "$PHP_DBA" != "no" && test "$HAVE_DBA" = "1"; then
+  if test "$PHP_DBA" != "no" || test "$HAVE_DBA" = "1"; then
     PHP_DBA_BUILTIN_CDB
   fi
 ])
@@ -511,7 +527,7 @@
     PHP_DBA_BUILTIN_INI
   fi
 ],[
-  if test "$PHP_DBA" != "no" && test "$HAVE_DBA" = "1"; then
+  if test "$PHP_DBA" != "no" || test "$HAVE_DBA" = "1"; then
     PHP_DBA_BUILTIN_INI
   fi
 ])
@@ -532,7 +548,7 @@
     PHP_DBA_BUILTIN_FLATFILE
   fi
 ],[
-  if test "$PHP_DBA" != "no" && test "$HAVE_DBA" = "1"; then
+  if test "$PHP_DBA" != "no" || test "$HAVE_DBA" = "1"; then
     PHP_DBA_BUILTIN_FLATFILE
   fi
 ])
