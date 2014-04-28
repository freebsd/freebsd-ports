--- common/autoconf/toolchain.m4.orig	2014-04-26 00:48:48.000000000 -0400
+++ common/autoconf/toolchain.m4	2014-04-26 00:49:35.000000000 -0400
@@ -885,7 +885,7 @@
   CCXXFLAGS_JDK="$CCXXFLAGS_JDK $ADD_LP64"
 
   # The package path is used only on macosx?
-  PACKAGE_PATH=/opt/local
+  PACKAGE_PATH=%%LOCALBASE%%
   AC_SUBST(PACKAGE_PATH)
 
   if test "x$OPENJDK_TARGET_CPU_ENDIAN" = xlittle; then
