--- make/autoconf/toolchain.m4
+++ make/autoconf/toolchain.m4
@@ -998,22 +998,7 @@ AC_DEFUN_ONCE([TOOLCHAIN_MISC_CHECKS],
 [
   # The package path is used only on macosx?
   # FIXME: clean this up, and/or move it elsewhere.
-  AC_ARG_WITH(package-path, [AS_HELP_STRING([--with-package-path],
-      [package path to be used for location of third party packages])])
-  PACKAGE_PATH="$with_package_path"
-  if test "x$PACKAGE_PATH" = x; then
-    case $OPENJDK_TARGET_OS_ENV in
-      bsd.freebsd|bsd.openbsd)
-        PACKAGE_PATH=/usr/local
-        ;;
-      bsd.netbsd)
-        PACKAGE_PATH=/usr/pkg
-        ;;
-      *)
-        PACKAGE_PATH=/opt/local
-        ;;
-    esac
-  fi
+  PACKAGE_PATH=/opt/local
   AC_SUBST(PACKAGE_PATH)
 
   # Check for extra potential brokenness.
