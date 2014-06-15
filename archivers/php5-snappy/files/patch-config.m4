--- config.m4.orig	2011-09-07 10:27:21.000000000 +0200
+++ config.m4	2014-05-17 13:31:39.000000000 +0200
@@ -53,7 +53,7 @@
 
   if test "$PHP_SNAPPY_INCLUDEDIR" != "no" && test "$PHP_SNAPPY_INCLUDEDIR" != "yes"; then
     if test -r "$PHP_SNAPPY_INCLUDEDIR/snappy.h"; then
-      SNAPPY_DIR="$PHP_SNAPPY_INCLUDEDIR"
+      SNAPPY_DIR="$(dirname $PHP_SNAPPY_INCLUDEDIR)"
     else
       AC_MSG_ERROR([Can't find snappy headers under "$PHP_SNAPPY_INCLUDEDIR"])
     fi
@@ -61,12 +61,12 @@
     SEARCH_PATH="/usr/local /usr"     # you might want to change this
     SEARCH_FOR="/include/snappy-c.h"  # you most likely want to change this
     if test -r $PHP_SNAPPY/$SEARCH_FOR; then # path given as parameter
-      SNAPPY_DIR="$PHP_SNAPPY/include"
+      SNAPPY_DIR="$PHP_SNAPPY"
     else # search default path list
       AC_MSG_CHECKING([for snappy files in default path])
       for i in $SEARCH_PATH ; do
         if test -r $i/$SEARCH_FOR; then
-          SNAPPY_DIR="$i/include"
+          SNAPPY_DIR="$i"
           AC_MSG_RESULT(found in $i)
         fi
       done
@@ -80,7 +80,7 @@
 
   dnl # add include path
 
-  PHP_ADD_INCLUDE($SNAPPY_DIR)
+  PHP_ADD_INCLUDE([$SNAPPY_DIR/include])
 
   dnl # check for lib
 
@@ -90,7 +90,7 @@
   AC_LANG_CPLUSPLUS
   AC_TRY_COMPILE(
   [
-    #include "$SNAPPY_DIR/snappy-c.h"
+    #include "$SNAPPY_DIR/include/snappy-c.h"
   ],[
     snappy_max_compressed_length(1);
   ],[
