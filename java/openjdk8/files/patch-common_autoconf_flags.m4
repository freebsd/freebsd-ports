--- common/autoconf/flags.m4.orig	2024-01-02 12:56:28 UTC
+++ common/autoconf/flags.m4
@@ -642,7 +642,7 @@ AC_DEFUN_ONCE([FLAGS_SETUP_COMPILER_FLAGS_FOR_JDK],
       CCXXFLAGS_JDK="$CCXXFLAGS_JDK -DVM_BIG_ENDIAN"
     fi
   fi
-  if test "x$OPENJDK_TARGET_CPU" = xppc64le; then
+  if test "x$OPENJDK_TARGET_CPU" = xppc64le -o "x$OPENJDK_TARGET_CPU" = xppc64; then
     CCXXFLAGS_JDK="$CCXXFLAGS_JDK -DABI_ELFv2"
   fi
   
