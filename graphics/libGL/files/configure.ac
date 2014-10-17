--- configure.ac.orig	2014-08-21 01:41:38.000000000 +0200
+++ configure.ac	2014-08-29 13:40:20.688548140 +0200
@@ -37,6 +37,7 @@
 DRI3PROTO_REQUIRED=1.0
 PRESENTPROTO_REQUIRED=1.0
 LIBUDEV_REQUIRED=151
+LIBDEVQ_REQUIRED=0.0.2
 GLPROTO_REQUIRED=1.4.14
 LIBOMXIL_BELLAGIO_REQUIRED=0.0
 VDPAU_REQUIRED=0.4.1
@@ -53,7 +54,7 @@
 AM_PROG_CC_C_O
 AM_PROG_AS
 AC_CHECK_PROGS([MAKE], [gmake make])
-AC_CHECK_PROGS([PYTHON2], [python2 python])
+AC_CHECK_PROGS([PYTHON2], [python2.7 python2 python])
 AC_PROG_SED
 AC_PROG_MKDIR_P
 
@@ -152,7 +153,7 @@
 DEFINES="-DUSE_EXTERNAL_DXTN_LIB=1"
 AC_SUBST([DEFINES])
 case "$host_os" in
-linux*|*-gnu*|gnu*)
+linux*|*-gnu*|gnu*|freebsd*)
     DEFINES="$DEFINES -D_GNU_SOURCE -DHAVE_PTHREAD"
     ;;
 solaris*)
@@ -581,7 +582,7 @@
     [enable_dri=yes])
 
 case "$host_os" in
-linux*)
+linux*|freebsd*)
     dri3_default=yes
     ;;
 *)
@@ -855,6 +856,9 @@
 PKG_CHECK_MODULES([LIBUDEV], [libudev >= $LIBUDEV_REQUIRED],
                   have_libudev=yes, have_libudev=no)
 
+PKG_CHECK_MODULES([LIBDEVQ], [libdevq-1.0 >= $LIBDEVQ_REQUIRED],
+                  have_libdevq=yes, have_libdevq=no)
+
 AC_ARG_ENABLE([sysfs],
     [AS_HELP_STRING([--enable-sysfs],
         [enable /sys PCI identification @<:@default=disabled@:>@])],
@@ -949,6 +953,10 @@
     DEFINES="$DEFINES -DHAVE_LIBUDEV"
     have_pci_id=yes
 fi
+if test "$have_libdevq" = yes; then
+    DEFINES="$DEFINES -DHAVE_LIBDEVQ"
+    have_pci_id=yes
+fi
 
 if test "$have_sysfs" = yes; then
     DEFINES="$DEFINES -DHAVE_SYSFS"
@@ -1069,6 +1077,23 @@
     *freebsd* | dragonfly* | *netbsd* | openbsd*)
         DEFINES="$DEFINES -DHAVE_PTHREAD"
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
     gnu*)
         DEFINES="$DEFINES -DHAVE_ALIAS"
@@ -1252,6 +1277,8 @@
 AM_CONDITIONAL(HAVE_GBM, test "x$enable_gbm" = xyes)
 if test "x$need_pci_id$have_libudev" = xyesyes; then
     GBM_PC_REQ_PRIV="libudev >= $LIBUDEV_REQUIRED"
+elif test "x$need_libdevq" = xyes; then
+    GBM_PC_REQ_PRIV="libdevq-1.0 >= $LIBDEVQ_REQUIRED"
 else
     GBM_PC_REQ_PRIV=""
 fi
@@ -1728,8 +1755,6 @@
                 CLANG_LIBDIR=${LLVM_LIBDIR}
             fi
             CLANG_RESOURCE_DIR=$CLANG_LIBDIR/clang/${LLVM_VERSION}
-            AS_IF([test ! -f "$CLANG_RESOURCE_DIR/include/stddef.h"],
-                [AC_MSG_ERROR([Could not find clang internal header stddef.h in $CLANG_RESOURCE_DIR Use --with-clang-libdir to specify the correct path to the clang libraries.])])
         fi
     else
         MESA_LLVM=0
