--- adm_local/unix/config_files/check_NETGENPLUGIN.m4.orig	2010-11-08 09:27:11.000000000 +0600
+++ adm_local/unix/config_files/check_NETGENPLUGIN.m4	2010-11-08 09:28:22.000000000 +0600
@@ -38,7 +38,7 @@
 	    [  --with-netgenplugin=DIR root directory path of NETGEN mesh plugin installation ],
 	    NETGENPLUGIN_DIR="$withval",NETGENPLUGIN_DIR="")
 
-if test "x$NETGENPLUGIN_DIR" == "x" ; then
+if test "x$NETGENPLUGIN_DIR" = "x" ; then
 
 # no --with-netgenplugin-dir option used
 
@@ -55,7 +55,7 @@
    NGplugin_ok=yes
    AC_MSG_RESULT(Using NETGEN mesh plugin distribution in ${NETGENPLUGIN_DIR})
 
-   if test "x$NETGENPLUGIN_ROOT_DIR" == "x" ; then
+   if test "x$NETGENPLUGIN_ROOT_DIR" = "x" ; then
       NETGENPLUGIN_ROOT_DIR=${NETGENPLUGIN_DIR}
    fi
    AC_SUBST(NETGENPLUGIN_ROOT_DIR)
