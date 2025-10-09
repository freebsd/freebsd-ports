# Use system dlib instead of bundled version
# - Replace bundled dlib detection with pkg-config
# - Use system dlib from science/dlib-cpp port
# - Remove hardcoded paths to bundled dlib-19.24
--- m4/ac_rna_build_requirements.m4.orig	2024-06-01 20:46:46 UTC
+++ m4/ac_rna_build_requirements.m4
@@ -253,28 +253,18 @@ AC_DEFUN([RNA_CHECK_DLIB], [
 
 AC_DEFUN([RNA_CHECK_DLIB], [
   AX_CXX_COMPILE_STDCXX(17, noext, mandatory)
-  DLIB_VERSION=19.24
-  DLIB_DIR="dlib-${DLIB_VERSION}"
-  DLIB_PATH="${srcdir}/src/${DLIB_DIR}"
-  DLIB_SRC_FILE="${DLIB_PATH}/dlib/all/source.cpp"
 
-  AC_RNA_TEST_FILE($DLIB_SRC_FILE,[],[
+  dnl Check for system dlib using pkg-config
+  PKG_CHECK_MODULES([DLIB], [dlib-1 >= 19.0], [
+    AC_DEFINE([HAVE_DLIB], [1], [Define if you have dlib])
+  ], [
     AC_MSG_ERROR([
-=================================================
-Can't find dlib's source.cpp
-
-Make sure you've unpacked 'src/dlib-${DLIB_VERSION}.tar.bz2'!
-
-Usually, you only need to execute the following command:
-
-tar -xjf src/dlib-${DLIB_VERSION}.tar.bz2 -C src/
-=================================================
-])
+dlib development library not found. Please install dlib-cpp port.
+    ])
   ])
 
-  AC_SUBST(DLIB_CPPFLAGS, "-I\$(top_srcdir)/src/${DLIB_DIR} -DDLIB_NO_GUI_SUPPORT")
-  AC_SUBST(DLIB_DIR)
-  AC_SUBST(DLIB_VERSION)
+  AC_SUBST(DLIB_CPPFLAGS, "${DLIB_CFLAGS} -DDLIB_NO_GUI_SUPPORT")
+  AC_SUBST(DLIB_LIBS, "${DLIB_LIBS}")
 
 ])
 
