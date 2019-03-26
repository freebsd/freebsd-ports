--- make/autoconf/lib-cups.m4
+++ make/autoconf/lib-cups.m4
@@ -75,14 +75,6 @@ AC_DEFUN_ONCE([LIB_SETUP_CUPS],
           DEFAULT_CUPS=yes
       ])
     fi
-    if test "x$CUPS_FOUND" = xno -a "x$OPENJDK_TARGET_OS" = xbsd; then
-      AC_MSG_CHECKING([for cups headers])
-      if test -s "${PACKAGE_PATH}/include/cups/cups.h"; then
-        CUPS_CFLAGS="-I${PACKAGE_PATH}/include"
-        CUPS_FOUND=yes
-      fi
-      AC_MSG_RESULT([$CUPS_FOUND])
-    fi
     if test "x$CUPS_FOUND" = xno; then
       HELP_MSG_MISSING_DEPENDENCY([cups])
       AC_MSG_ERROR([Could not find cups! $HELP_MSG ])
