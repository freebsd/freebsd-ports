--- adm_local/unix/config_files/check_RANDOMIZER.m4.orig	2009-08-15 12:27:55.000000000 +0700
+++ adm_local/unix/config_files/check_RANDOMIZER.m4	2009-08-15 12:28:05.000000000 +0700
@@ -37,7 +37,7 @@
 	    [  --with-rnd=DIR root directory path of RANDOMIZER module installation ],
 	    RANDOMIZER_DIR="$withval",RANDOMIZER_DIR="")
 
-if test "x$RANDOMIZER_DIR" == "x" ; then
+if test "x$RANDOMIZER_DIR" = "x" ; then
    # no --with-rnd-dir option used
    if test "x$RANDOMIZER_ROOT_DIR" != "x" ; then
       # RANDOMIZER_ROOT_DIR environment variable defined
@@ -49,7 +49,7 @@
    Randomizer_ok=yes
    AC_MSG_RESULT(Using Randomizer module distribution in ${RANDOMIZER_DIR})
 
-   if test "x$RANDOMIZER_ROOT_DIR" == "x" ; then
+   if test "x$RANDOMIZER_ROOT_DIR" = "x" ; then
       RANDOMIZER_ROOT_DIR=${RANDOMIZER_DIR}
    fi
 
