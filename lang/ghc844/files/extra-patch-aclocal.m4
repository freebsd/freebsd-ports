--- aclocal.m4.orig	2018-03-25 21:22:32 UTC
+++ aclocal.m4
@@ -648,6 +648,14 @@ AC_DEFUN([FPTOOLS_SET_C_LD_FLAGS],
         $3="$$3 -D_HPUX_SOURCE"
         $5="$$5 -D_HPUX_SOURCE"
         ;;
+    arm*freebsd*)
+        # On arm/freebsd, tell gcc to generate Arm
+        # instructions (ie not Thumb) and to link using the gold linker.
+        # Forcing LD to be ld.gold is done in FIND_LD m4 macro.
+        $2="$$2 -marm"
+        $3="$$3 -Wl,-z,noexecstack"
+        $4="$$4 -z noexecstack"
+        ;;
     arm*linux*)
         # On arm/linux and arm/android, tell gcc to generate Arm
         # instructions (ie not Thumb).
@@ -656,6 +664,11 @@ AC_DEFUN([FPTOOLS_SET_C_LD_FLAGS],
         $4="$$4 -z noexecstack"
         ;;
 
+    aarch64*freebsd*)
+        $3="$$3 -Wl,-z,noexecstack"
+        $4="$$4 -z noexecstack"
+        ;;
+
     aarch64*linux*)
         $3="$$3 -Wl,-z,noexecstack"
         $4="$$4 -z noexecstack"
@@ -1917,6 +1930,10 @@ case "$1" in
 # converts the canonicalized target into someting llvm can understand
 AC_DEFUN([GHC_LLVM_TARGET], [
   case "$2-$3" in
+    *-freebsd*-gnueabihf)
+      llvm_target_vendor="unknown"
+      llvm_target_os="freebsd-gnueabihf"
+      ;;
     hardfloat-*eabi)
       llvm_target_vendor="unknown"
       llvm_target_os="$3""hf"
@@ -2361,13 +2378,6 @@ AC_DEFUN([FIND_LD],[
       [enable_ld_override=yes])
 
     find_ld() {
-        # Make sure the user didn't specify LD manually.
-        if test "z$LD" != "z"; then
-            AC_CHECK_TARGET_TOOL([LD], [ld])
-            LD_NO_GOLD=$LD
-            return
-        fi
-
         # Manually iterate over possible names since we want to ensure that, e.g.,
         # if ld.lld is installed but gcc doesn't support -fuse-ld=lld, that we
         # then still try ld.gold and -fuse-ld=gold.
