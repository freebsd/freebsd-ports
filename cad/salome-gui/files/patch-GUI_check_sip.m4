--- adm_local/unix/config_files/check_sip.m4.orig	2009-10-17 18:43:27.000000000 +0700
+++ adm_local/unix/config_files/check_sip.m4	2009-10-17 18:43:42.000000000 +0700
@@ -77,20 +77,20 @@
     for d in ${TEST_INC_DIRS} ; do
         if test -d $d ; then
             AC_CHECK_FILE(${d}/sip.h,sip_ok=yes,sip_ok=no)
-      	    if test "x$sip_ok" == "xyes" ; then
+      	    if test "x$sip_ok" = "xyes" ; then
 	        SIP_INCLUDES="-I${d}"
                 break
             fi
         fi
     done
 
-    if test "x$sip_ok" == "xyes" ; then
+    if test "x$sip_ok" = "xyes" ; then
         dnl Search sip.so file
         sip_ok=no
         for d in ${TEST_LIB_DIRS} ; do
             if test -d $d ; then
                 AC_CHECK_FILE(${d}/sip.so,sip_ok=yes,sip_ok=no)
-      	        if test "x$sip_ok" == "xyes" ; then
+      	        if test "x$sip_ok" = "xyes" ; then
                     if test "x${d}" = "x/usr/lib${LIB_LOCATION_SUFFIX}" ; then
                         SIP_LIBS=""
                     else
