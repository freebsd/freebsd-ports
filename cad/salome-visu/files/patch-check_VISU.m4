--- adm_local/unix/config_files/check_VISU.m4.orig	2009-08-14 21:49:26.000000000 +0700
+++ adm_local/unix/config_files/check_VISU.m4	2009-08-14 21:49:34.000000000 +0700
@@ -40,7 +40,7 @@
 	    [  --with-visu=DIR root directory path of VISU module installation ],
 	    VISU_DIR="$withval",VISU_DIR="")
 
-if test "x$VISU_DIR" == "x" ; then
+if test "x$VISU_DIR" = "x" ; then
    # no --with-visu-dir option used
    if test "x$VISU_ROOT_DIR" != "x" ; then
       # VISU_ROOT_DIR environment variable defined
@@ -52,7 +52,7 @@
    Visu_ok=yes
    AC_MSG_RESULT(Using VISU module distribution in ${VISU_DIR})
 
-   if test "x$VISU_ROOT_DIR" == "x" ; then
+   if test "x$VISU_ROOT_DIR" = "x" ; then
       VISU_ROOT_DIR=${VISU_DIR}
    fi
    AC_SUBST(VISU_ROOT_DIR)
