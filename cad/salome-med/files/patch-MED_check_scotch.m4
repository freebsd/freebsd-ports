--- adm_local/unix/config_files/check_scotch.m4.orig	2009-05-28 22:09:03.000000000 +0700
+++ adm_local/unix/config_files/check_scotch.m4	2009-07-30 14:52:49.000000000 +0700
@@ -44,7 +44,7 @@
 
 if test "x${SCOTCHDIR}" != "x" ; then
   SCOTCH_CPPFLAGS="-DENABLE_SCOTCH -I${SCOTCHDIR}"
-  SCOTCH_LIBS="-L${SCOTCHDIR}/bin -lscotch -lscotcherr"
+  SCOTCH_LIBS="-L${SCOTCHDIR}/lib -lscotch -lscotcherr"
 fi
 
 scotch_ok=no
@@ -57,14 +57,14 @@
 
 scotch_include_dir_ok=yes
 if test "x${SCOTCHDIR}" != "x" ; then
-  AC_CHECK_FILE(${SCOTCHDIR}/bin/scotch.h,
+  AC_CHECK_FILE(${SCOTCHDIR}/include/scotch.h,
                 scotch_include_dir_ok=yes,
                 scotch_include_dir_ok=no)
 fi
 
 if test "x${scotch_include_dir_ok}" = "xyes" ; then
   AC_TRY_COMPILE([#include <stdio.h>
-		  #include <bin/scotch.h>],
+		  #include <scotch.h>],
                  [SCOTCH_Graph* graph;
 		  SCOTCH_graphInit(graph)],
                  scotch_headers_ok=yes,
@@ -83,12 +83,12 @@
   AC_CHECKING(for SCOTCH binaries)
   scotch_lib_dir_ok=yes
   if test "x${SCOTCHDIR}" != "x" ; then
-    AC_CHECK_FILE(${SCOTCHDIR}/bin/libscotch.a,
+    AC_CHECK_FILE(${SCOTCHDIR}/lib/libscotch.a,
                   scotch_lib_dir_ok=yes,
                   scotch_lib_dir_ok=no)
     if test "x${scotch_lib_dir_ok}" = "xno" ; then
       SCOTCH_LIBSUFFIX=""
-      AC_CHECK_FILE(${SCOTCHDIR}/bin/libscotch.a,
+      AC_CHECK_FILE(${SCOTCHDIR}/lib/libscotch.a,
                     scotch_lib_dir_ok=yes,
                     scotch_lib_dir_ok=no)
     fi
@@ -96,7 +96,7 @@
   if test "x${scotch_lib_dir_ok}" = "xyes" ; then
     LIBS="${LIBS_old} ${SCOTCH_LIBS}"
     AC_TRY_LINK([#include <stdio.h>
-		#include <bin/scotch.h>],
+		#include <scotch.h>],
                   [SCOTCH_Graph* graph;
 		  SCOTCH_graphInit(graph)],
                 scotch_binaries_ok=yes,
@@ -105,7 +105,7 @@
       SCOTCH_LIBSUFFIX=""
       LIBS="${LIBS_old} ${SCOTCH_LIBS} "
       AC_TRY_LINK([#include <stdio.h>
-		   #include <bin/scotch.h>],
+		   #include <scotch.h>],
                   [SCOTCH_Graph* graph;
 		  SCOTCH_graphInit(graph)],
                   scotch_binaries_ok=yes,
