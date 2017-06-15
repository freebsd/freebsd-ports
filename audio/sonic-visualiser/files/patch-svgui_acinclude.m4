--- svgui/acinclude.m4.orig	2015-10-22 11:26:02 UTC
+++ svgui/acinclude.m4
@@ -30,33 +30,12 @@ fi
 
 AC_DEFUN([SV_MODULE_OPTIONAL],
 [
-SV_MODULE_MODULE=$1
-SV_MODULE_VERSION_TEST="$2"
-SV_MODULE_HEADER=$3
-SV_MODULE_LIB=$4
-SV_MODULE_FUNC=$5
-SV_MODULE_HAVE=HAVE_$(echo $1 | tr '[a-z]' '[A-Z]')
-SV_MODULE_FAILED=1
-if test -n "$$1_LIBS" ; then
-   AC_MSG_NOTICE([User set ${SV_MODULE_MODULE}_LIBS explicitly, skipping test for $SV_MODULE_MODULE])
-   CXXFLAGS="$CXXFLAGS $$1_CFLAGS"
-   LIBS="$LIBS $$1_LIBS"
-   SV_MODULE_FAILED=""
-fi
-if test -z "$SV_MODULE_VERSION_TEST" ; then
-   SV_MODULE_VERSION_TEST=$SV_MODULE_MODULE
-fi
-if test -n "$SV_MODULE_FAILED" && test -n "$PKG_CONFIG"; then
-   PKG_CHECK_MODULES($1,[$SV_MODULE_VERSION_TEST],[HAVES="$HAVES $SV_MODULE_HAVE";CXXFLAGS="$CXXFLAGS $$1_CFLAGS";LIBS="$LIBS $$1_LIBS";SV_MODULE_FAILED=""],[AC_MSG_NOTICE([Failed to find optional module $SV_MODULE_MODULE using pkg-config, trying again by old-fashioned means])])
-fi
-if test -n "$SV_MODULE_FAILED"; then
-   AC_CHECK_HEADER([$SV_MODULE_HEADER],[HAVES="$HAVES $SV_MODULE_HAVE";SV_MODULE_FAILED=""],[AC_MSG_NOTICE([Failed to find header $SV_MODULE_HEADER for optional module $SV_MODULE_MODULE])])
-   if test -z "$SV_MODULE_FAILED"; then
-      if test -n "$SV_MODULE_LIB"; then
-           AC_CHECK_LIB([$SV_MODULE_LIB],[$SV_MODULE_FUNC],[LIBS="$LIBS -l$SV_MODULE_LIB"],[AC_MSG_NOTICE([Failed to find library $SV_MODULE_LIB for optional module $SV_MODULE_MODULE])])
-      fi
-   fi
-fi
+AC_ARG_WITH([$4],
+            [AS_HELP_STRING([--with-$4],
+                            [Enable support for $1 [default=no]])],
+            [],
+            [with_$4=no])
+AS_IF([test "x$with_$4" = xyes], [SV_MODULE_REQUIRED($1,$2,$3,$4,$5)])
 ])
 
 # Check for Qt.  The only part of Qt we use directly is qmake.
