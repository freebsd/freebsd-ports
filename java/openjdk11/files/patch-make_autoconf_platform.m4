--- make/autoconf/platform.m4
+++ make/autoconf/platform.m4
@@ -497,6 +497,8 @@ AC_DEFUN([PLATFORM_SETUP_LEGACY_VARS_HELPER],
     OPENJDK_$1_OS_INCLUDE_SUBDIR="win32"
   elif test "x$OPENJDK_TARGET_OS" = "xmacosx"; then
     OPENJDK_$1_OS_INCLUDE_SUBDIR="darwin"
+  elif test "x$OPENJDK_TARGET_OS" = "xbsd"; then
+    OPENJDK_$1_OS_INCLUDE_SUBDIR=`echo ${OPENJDK_TARGET_OS_ENV} | cut -d'.' -f2`
   fi
   AC_SUBST(OPENJDK_$1_OS_INCLUDE_SUBDIR)
 ])
