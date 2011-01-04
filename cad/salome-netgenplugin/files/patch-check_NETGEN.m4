--- adm_local/unix/config_files/check_NETGEN.m4.orig	2010-11-08 09:26:42.000000000 +0600
+++ adm_local/unix/config_files/check_NETGEN.m4	2010-11-08 09:26:53.000000000 +0600
@@ -41,7 +41,7 @@
 
 Netgen_ok=no
 
-if test "x$NETGEN_HOME" == "x" ; then
+if test "x$NETGEN_HOME" = "x" ; then
 
 # no --with-netgen option used
    if test "x$NETGENHOME" != "x" ; then
@@ -100,7 +100,7 @@
   AC_MSG_CHECKING(for Netgen header file)
 
   AC_CHECK_HEADER(nglib.h,Netgen_ok=yes,Netgen_ok=no)
-  if test "x$Netgen_ok" == "xyes"; then
+  if test "x$Netgen_ok" = "xyes"; then
 
     if test "$NETGEN_NEW" = "no" ; then
 
@@ -218,7 +218,7 @@
       Netgen_ok="$salome_cv_netgen_salome_patch_lib"
       fi
 
-      if test "x$Netgen_ok" == xno ; then
+      if test "x$Netgen_ok" = xno ; then
       AC_MSG_RESULT(no)
       AC_MSG_ERROR(Netgen is not properly installed)
       fi
@@ -233,7 +233,7 @@
   CPPFLAGS="$CPPFLAGS_old"
   CXXFLAGS="$CXXFLAGS_old"
 
-  if test "x$Netgen_ok" == xno ; then
+  if test "x$Netgen_ok" = xno ; then
     AC_MSG_RESULT(no)
     AC_MSG_WARN(Netgen libraries not found or not properly installed)
   else
