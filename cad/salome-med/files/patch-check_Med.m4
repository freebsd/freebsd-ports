--- adm_local/unix/config_files/check_Med.m4.orig	2009-08-14 20:34:25.000000000 +0700
+++ adm_local/unix/config_files/check_Med.m4	2009-08-14 20:34:47.000000000 +0700
@@ -39,7 +39,7 @@
 	    [  --with-med=DIR root directory path of MED installation ],
 	    MED_DIR="$withval",MED_DIR="")
 
-if test "x${MED_DIR}" == "x" ; then
+if test "x${MED_DIR}" = "x" ; then
   AC_MSG_RESULT(for \${MED_ROOT_DIR}: ${MED_ROOT_DIR})
 # no --with-med-dir option used
    if test "x${MED_ROOT_DIR}" != "x" ; then
@@ -57,7 +57,7 @@
    AC_MSG_RESULT(Using Med module distribution in ${MED_DIR})
    Med_ok=yes
 
-   if test "x$MED_ROOT_DIR" == "x" ; then
+   if test "x$MED_ROOT_DIR" = "x" ; then
       MED_ROOT_DIR=${MED_DIR}
    fi
 
