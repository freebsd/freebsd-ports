--- config.m4.orig	Mon Aug  7 09:57:12 2006
+++ config.m4	Sat Nov  4 11:18:16 2006
@@ -244,6 +244,18 @@
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
@@ -493,7 +505,7 @@
     PHP_DBA_STD_ATTACH
   fi
 ],[
-  if test "$PHP_DBA" != "no" && test "$HAVE_DBA" = "1"; then
+  if test "$PHP_DBA" != "no" || test "$HAVE_DBA" = "1"; then
     PHP_DBA_BUILTIN_CDB
   fi
 ])
@@ -511,7 +523,7 @@
     PHP_DBA_BUILTIN_INI
   fi
 ],[
-  if test "$PHP_DBA" != "no" && test "$HAVE_DBA" = "1"; then
+  if test "$PHP_DBA" != "no" || test "$HAVE_DBA" = "1"; then
     PHP_DBA_BUILTIN_INI
   fi
 ])
@@ -532,7 +544,7 @@
     PHP_DBA_BUILTIN_FLATFILE
   fi
 ],[
-  if test "$PHP_DBA" != "no" && test "$HAVE_DBA" = "1"; then
+  if test "$PHP_DBA" != "no" || test "$HAVE_DBA" = "1"; then
     PHP_DBA_BUILTIN_FLATFILE
   fi
 ])
