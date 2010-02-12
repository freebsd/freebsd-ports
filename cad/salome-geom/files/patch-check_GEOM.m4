--- adm_local/unix/config_files/check_GEOM.m4.orig	2009-10-20 20:21:02.000000000 +0700
+++ adm_local/unix/config_files/check_GEOM.m4	2009-10-20 20:21:16.000000000 +0700
@@ -37,7 +37,7 @@
 	    [  --with-geom=DIR root directory path of GEOM installation ],
 	    GEOM_DIR="$withval",GEOM_DIR="")
 
-if test "x$GEOM_DIR" == "x" ; then
+if test "x$GEOM_DIR" = "x" ; then
 
 # no --with-geom-dir option used
 
@@ -63,7 +63,7 @@
    Geom_ok=yes
    AC_MSG_RESULT(Using Geom module distribution in ${GEOM_DIR})
 
-   if test "x$GEOM_ROOT_DIR" == "x" ; then
+   if test "x$GEOM_ROOT_DIR" = "x" ; then
       GEOM_ROOT_DIR=${GEOM_DIR}
    fi
    AC_SUBST(GEOM_ROOT_DIR)
