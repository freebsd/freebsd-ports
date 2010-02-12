--- adm_local/unix/config_files/check_metis.m4.orig	2009-05-28 22:09:03.000000000 +0700
+++ adm_local/unix/config_files/check_metis.m4	2009-07-30 15:07:50.000000000 +0700
@@ -43,8 +43,8 @@
 LIBS_old=$LIBS
 
 if test "x${METISDIR}" != "x" ; then
-  METIS_CPPFLAGS="-DENABLE_METIS -I${METISDIR}/Lib"
-  METIS_LIBS="-L${METISDIR} -lmetis"
+  METIS_CPPFLAGS="-DENABLE_METIS -I${METISDIR}/include/metis"
+  METIS_LIBS="-L${METISDIR}/lib -lmetis"
 fi
 
 metis_ok=no
@@ -57,13 +57,13 @@
 
 metis_include_dir_ok=yes
 if test "x${METISDIR}" != "x" ; then
-  AC_CHECK_FILE(${METISDIR}/Lib/metis.h,
+  AC_CHECK_FILE(${METISDIR}/include/metis/metis.h,
                 metis_include_dir_ok=yes,
                 metis_include_dir_ok=no)
 fi
 
 if test "x${metis_include_dir_ok}" = "xyes" ; then
-  AC_TRY_COMPILE([#include <metis.h>],
+  AC_TRY_COMPILE([#include <metis/metis.h>],
                  [Change2CNumbering(0,0,0)],
                  metis_headers_ok=yes,
                  metis_headers_ok=no)
@@ -81,26 +81,26 @@
   AC_CHECKING(for METIS binaries)
   metis_lib_dir_ok=yes
   if test "x${METISDIR}" != "x" ; then
-    AC_CHECK_FILE(${METISDIR}/libmetis.a,
+    AC_CHECK_FILE(${METISDIR}/lib/libmetis.a,
                   metis_lib_dir_ok=yes,
                   metis_lib_dir_ok=no)
     if test "x${metis_lib_dir_ok}" = "xno" ; then
       METIS_LIBSUFFIX=""
-      AC_CHECK_FILE(${METISDIR}/libmetis.a,
+      AC_CHECK_FILE(${METISDIR}/lib/libmetis.a,
                     metis_lib_dir_ok=yes,
                     metis_lib_dir_ok=no)
     fi
   fi
   if test "x${metis_lib_dir_ok}" = "xyes" ; then
     LIBS="${LIBS_old} ${METIS_LIBS}"
-    AC_TRY_LINK([#include <metis.h>],
+    AC_TRY_LINK([#include <metis/metis.h>],
                 [Change2CNumbering(0,0,0)],
                 metis_binaries_ok=yes,
                 metis_binaries_ok=no)
     if test "x${metis_binaries_ok}" = "xno" ; then
       METIS_LIBSUFFIX=""
       LIBS="${LIBS_old} ${METIS_LIBS} "
-      AC_TRY_LINK([#include <metis.h>],
+      AC_TRY_LINK([#include <metis/metis.h>],
                   [Change2CNumbering(0,0,0)],
                   metis_binaries_ok=yes,
                   metis_binaries_ok=no)
