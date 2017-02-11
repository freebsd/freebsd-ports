--- configure.ac.orig	2016-06-21 14:31:09.000000000 +0200
+++ configure.ac	2016-07-08 13:05:53.236433000 +0200
@@ -871,7 +872,7 @@
     [enable_dri=yes])
 
 case "$host_os" in
-linux*)
+linux*|freebsd*)
     dri3_default=yes
     ;;
 *)
@@ -1540,6 +1548,19 @@
         ;;
     gnu*)
         DEFINES="$DEFINES -DHAVE_ALIAS"
+dnl not sure about dri3 support, just enable it for now.
+        if test "x$enable_dri3" = xyes; then
+            DEFINES="$DEFINES -DHAVE_DRI3"
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
@@ -1921,9 +1948,19 @@
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
@@ -2102,9 +2139,9 @@
 strip_unwanted_llvm_flags() {
     # Use \> (marks the end of the word)
     echo `$1` | sed \
-	-e 's/-march=\S*//g' \
-	-e 's/-mtune=\S*//g' \
-	-e 's/-mcpu=\S*//g' \
+	-e 's/-march=[[:graph:]]* //g' \
+	-e 's/-mtune=[[:graph:]]* //g' \
+	-e 's/-mcpu=[[:graph:]]* //g' \
 	-e 's/-DNDEBUG\>//g' \
 	-e 's/-D_GNU_SOURCE\>//g' \
 	-e 's/-pedantic\>//g' \
@@ -2196,8 +2233,6 @@
                 CLANG_LIBDIR=${LLVM_LIBDIR}
             fi
             CLANG_RESOURCE_DIR=$CLANG_LIBDIR/clang/${LLVM_VERSION}
-            AS_IF([test ! -f "$CLANG_RESOURCE_DIR/include/stddef.h"],
-                [AC_MSG_ERROR([Could not find clang internal header stddef.h in $CLANG_RESOURCE_DIR Use --with-clang-libdir to specify the correct path to the clang libraries.])])
         fi
     else
         MESA_LLVM=0
