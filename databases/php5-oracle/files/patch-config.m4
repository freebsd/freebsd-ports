--- config.m4.orig	Thu Jul  8 10:22:35 2004
+++ config.m4	Thu Jul  8 10:30:31 2004
@@ -4,8 +4,8 @@
 
 AC_DEFUN(AC_ORACLE_VERSION,[
   AC_MSG_CHECKING([Oracle version])
-  if test -s "$ORACLE_DIR/orainst/unix.rgs"; then
-  	ORACLE_VERSION=`grep '"ocommon"' $ORACLE_DIR/orainst/unix.rgs | sed 's/[ ][ ]*/:/g' | cut -d: -f 6 | cut -c 2-4`
+  if test -s "$ORACLE_DIR/ocommon/install/partial.prd"; then
+  	ORACLE_VERSION=`grep '"ocommon"' $ORACLE_DIR/ocommon/install/partial.prd | sed 's/[ ][ ]*/:/g' | cut -d: -f 6 | cut -c 2-4`
 	test -z "$ORACLE_VERSION" && ORACLE_VERSION=7.3
   elif test -f $ORACLE_DIR/lib/libclntsh.$SHLIB_SUFFIX_NAME.9.0; then
     ORACLE_VERSION=9.0
@@ -113,6 +113,7 @@
 	    PHP_ADD_LIBRARY_WITH_PATH(clntsh, $ORACLE_DIR/lib, ORACLE_SHARED_LIBADD)
 	  else
 	    PHP_ADD_LIBRARY_WITH_PATH(core3, $ORACLE_DIR/lib, ORACLE_SHARED_LIBADD)
+	    PHP_ADD_LIBRARY_WITH_PATH(wrap, $ORACLE_DIR/lib, ORACLE_SHARED_LIBADD)
 	    PHP_ADD_LIBRARY_WITH_PATH(nlsrtl3, $ORACLE_DIR/lib, ORACLE_SHARED_LIBADD)
 	    PHP_ADD_LIBRARY_WITH_PATH(core3, $ORACLE_DIR/lib, ORACLE_SHARED_LIBADD)
 	    PHP_ADD_LIBRARY_WITH_PATH(c3v6, $ORACLE_DIR/lib, ORACLE_SHARED_LIBADD)
