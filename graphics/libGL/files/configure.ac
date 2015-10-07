--- configure.ac.orig	2015-03-28 19:20:39.000000000 +0100
+++ configure.ac	2015-03-29 12:20:43.817681000 +0200
@@ -68,6 +68,7 @@
 DRI3PROTO_REQUIRED=1.0
 PRESENTPROTO_REQUIRED=1.0
 LIBUDEV_REQUIRED=151
+LIBDEVQ_REQUIRED=0.0.2
 GLPROTO_REQUIRED=1.4.14
 LIBOMXIL_BELLAGIO_REQUIRED=0.0
 LIBVA_REQUIRED=0.35.0
@@ -87,7 +88,7 @@
 AM_PROG_CC_C_O
 AM_PROG_AS
 AX_CHECK_GNU_MAKE
-AC_CHECK_PROGS([PYTHON2], [python2 python])
+AC_CHECK_PROGS([PYTHON2], [python2.7 python2 python])
 AC_PROG_SED
 AC_PROG_MKDIR_P
 
@@ -689,7 +690,7 @@
     [enable_dri=yes])
 
 case "$host_os" in
-linux*)
+linux*|freebsd*)
     dri3_default=yes
     ;;
 *)
@@ -955,6 +956,9 @@
 PKG_CHECK_MODULES([LIBUDEV], [libudev >= $LIBUDEV_REQUIRED],
                   have_libudev=yes, have_libudev=no)
 
+PKG_CHECK_MODULES([LIBDEVQ], [libdevq-1.0 >= $LIBDEVQ_REQUIRED],
+                  have_libdevq=yes, have_libdevq=no)
+
 AC_ARG_ENABLE([sysfs],
     [AS_HELP_STRING([--enable-sysfs],
         [enable /sys PCI identification @<:@default=disabled@:>@])],
@@ -1051,6 +1055,10 @@
     DEFINES="$DEFINES -DHAVE_LIBUDEV"
     have_pci_id=yes
 fi
+if test "$have_libdevq" = yes; then
+    DEFINES="$DEFINES -DHAVE_LIBDEVQ"
+    have_pci_id=yes
+fi
 
 if test "$have_sysfs" = yes; then
     DEFINES="$DEFINES -DHAVE_SYSFS"
@@ -1173,6 +1181,23 @@
         ;;
     gnu*)
         DEFINES="$DEFINES -DHAVE_ALIAS"
+dnl not sure about dri3 support, just enable it for now.
+        if test "x$enable_dri3" = xyes; then
+            DEFINES="$DEFINES -DHAVE_DRI3"
+        fi
+
+        if test "x$have_libdevq" != xyes; then
+            AC_MSG_ERROR([libdevq required for building DRI])
+        fi
+
+        case "$host_cpu" in
+        powerpc* | sparc*)
+            # Build only the drivers for cards that exist on PowerPC/sparc
+            if test "x$with_dri_drivers" = "xyes"; then
+                with_dri_drivers="r200 radeon swrast"
+            fi
+            ;;
+        esac
         ;;
     cygwin*)
         if test "x$with_dri_drivers" = "xyes"; then
@@ -1350,6 +1375,8 @@
 AM_CONDITIONAL(HAVE_GBM, test "x$enable_gbm" = xyes)
 if test "x$need_pci_id$have_libudev" = xyesyes; then
     GBM_PC_REQ_PRIV="libudev >= $LIBUDEV_REQUIRED"
+elif test "x$need_libdevq" = xyes; then
+    GBM_PC_REQ_PRIV="libdevq-1.0 >= $LIBDEVQ_REQUIRED"
 else
     GBM_PC_REQ_PRIV=""
 fi
@@ -1528,9 +1555,19 @@
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
+# end of clang test.
+    fi
 
     if test "x$have_libclc" = xno; then
         AC_MSG_ERROR([pkg-config cannot find libclc.pc which is required to build clover.
@@ -1819,8 +1856,6 @@
                 CLANG_LIBDIR=${LLVM_LIBDIR}
             fi
             CLANG_RESOURCE_DIR=$CLANG_LIBDIR/clang/${LLVM_VERSION}
-            AS_IF([test ! -f "$CLANG_RESOURCE_DIR/include/stddef.h"],
-                [AC_MSG_ERROR([Could not find clang internal header stddef.h in $CLANG_RESOURCE_DIR Use --with-clang-libdir to specify the correct path to the clang libraries.])])
         fi
     else
         MESA_LLVM=0
