--- configure.ac.orig	2017-04-01 15:33:36 UTC
+++ configure.ac
@@ -1121,7 +1121,7 @@ fi
 AC_SUBST(LIBSENSORS_LIBS)
 
 case "$host_os" in
-linux*)
+linux* | freebsd*)
     dri3_default=yes
     ;;
 *)
@@ -2002,9 +2002,18 @@ if test "x$enable_opencl" = xyes; then
         AC_MSG_ERROR([cannot enable OpenCL without Gallium])
     fi
 
+    if test "x$acv_mesa_CLANG" = xno; then
+
+    GCC_VERSION=`$CC -dumpversion`
+    if test $? -eq 0; then
+        GCC_VERSION_MAJOR=`echo $GCC_VERSION | cut -d. -f1`
+        GCC_VERSION_MINOR=`echo $GCC_VERSION | cut -d. -f2`
+    fi
+
     if test $GCC_VERSION_MAJOR -lt 4 -o $GCC_VERSION_MAJOR -eq 4 -a $GCC_VERSION_MINOR -lt 7; then
         AC_MSG_ERROR([gcc >= 4.7 is required to build clover])
     fi
+    fi # end of clang test
 
     if test "x$have_libclc" = xno; then
         AC_MSG_ERROR([pkg-config cannot find libclc.pc which is required to build clover.
@@ -2061,8 +2070,6 @@ if test "x$enable_opencl" = xyes; then
         CLANG_LIBDIR=${LLVM_LIBDIR}
     fi
     CLANG_RESOURCE_DIR=$CLANG_LIBDIR/clang/${LLVM_VERSION}
-    AS_IF([test ! -f "$CLANG_RESOURCE_DIR/include/stddef.h"],
-        [AC_MSG_ERROR([Could not find clang internal header stddef.h in $CLANG_RESOURCE_DIR Use --with-clang-libdir to specify the correct path to the clang libraries.])])
 fi
 AM_CONDITIONAL(HAVE_CLOVER, test "x$enable_opencl" = xyes)
 AM_CONDITIONAL(HAVE_CLOVER_ICD, test "x$enable_opencl_icd" = xyes)
