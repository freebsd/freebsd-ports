--- ./aclocal.m4.orig	2014-07-10 06:27:16.000000000 +0200
+++ ./aclocal.m4	2014-07-11 11:23:41.000000000 +0200
@@ -47,6 +47,8 @@
     # In bindists, we haven't called AC_CANONICAL_{BUILD,HOST,TARGET}
     # so this justs uses $bootstrap_target.
 
+    bootstrap_target=`echo "$bootstrap_target" | sed -e 's/-unknown-/-portbld-/g'`
+
     if test "$build_alias" = ""
     then
         if test "$bootstrap_target" != ""
@@ -1817,7 +1819,7 @@
     dnl If special linker flags are needed to build things, then allow
     dnl the user to pass them in via LDFLAGS.
     changequote(, )dnl
-    GHC_LDFLAGS=`echo $LDFLAGS | sed 's/\(^\| \)\([^ ]\)/\1-optl\2/g'`
+    GHC_LDFLAGS=`echo $LDFLAGS | sed -r 's/(^| )([^ ])/\1-optl\2/g'`
     changequote([, ])dnl
     if ! "$WithGhc" $GHC_LDFLAGS -v0 -no-user-$GHC_PACKAGE_DB_FLAG -hidir utils/ghc-pwd/dist-boot -odir utils/ghc-pwd/dist-boot -stubdir utils/ghc-pwd/dist-boot --make utils/ghc-pwd/Main.hs -o utils/ghc-pwd/dist-boot/ghc-pwd
     then
