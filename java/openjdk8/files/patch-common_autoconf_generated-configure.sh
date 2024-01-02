--- common/autoconf/generated-configure.sh.orig	2024-01-02 12:56:13 UTC
+++ common/autoconf/generated-configure.sh
@@ -43317,7 +43317,7 @@ $as_echo "$supports" >&6; }
       CCXXFLAGS_JDK="$CCXXFLAGS_JDK -DVM_BIG_ENDIAN"
     fi
   fi
-  if test "x$OPENJDK_TARGET_CPU" = xppc64le; then
+  if test "x$OPENJDK_TARGET_CPU" = xppc64le -o "x$OPENJDK_TARGET_CPU" = xppc64; then
     CCXXFLAGS_JDK="$CCXXFLAGS_JDK -DABI_ELFv2"
   fi
 
