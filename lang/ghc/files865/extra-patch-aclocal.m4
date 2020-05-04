--- aclocal.m4.orig	2018-03-25 21:22:32 UTC
+++ aclocal.m4
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
