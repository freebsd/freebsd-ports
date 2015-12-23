--- common/autoconf/boot-jdk.m4.orig	2015-12-09 21:04:26 UTC
+++ common/autoconf/boot-jdk.m4
@@ -289,6 +289,16 @@ AC_DEFUN_ONCE([BOOTJDK_SETUP_BOOT_JDK],
   BOOT_JDK_SOURCETARGET="-source 7 -target 7"
   AC_SUBST(BOOT_JDK_SOURCETARGET)
   AC_SUBST(JAVAC_FLAGS)
+
+  # Check if the boot jdk is 32 or 64 bit
+  if "$JAVA" -d64 -version > /dev/null 2>&1; then
+    BOOT_JDK_BITS="64"
+  else
+    BOOT_JDK_BITS="32"
+  fi
+  AC_MSG_CHECKING([if Boot JDK is 32 or 64 bits])
+  AC_MSG_RESULT([$BOOT_JDK_BITS])
+  AC_SUBST(BOOT_JDK_BITS)
 ])
 
 AC_DEFUN_ONCE([BOOTJDK_SETUP_BOOT_JDK_ARGUMENTS],
@@ -323,7 +333,7 @@ AC_DEFUN_ONCE([BOOTJDK_SETUP_BOOT_JDK_AR
 
   # Maximum amount of heap memory.
   # Maximum stack size.
-  if test "x$BUILD_NUM_BITS" = x32; then
+  if test "x$BOOT_JDK_BITS" = x32; then
     JVM_MAX_HEAP=1100M
     STACK_SIZE=768
   else
