- DragonFly also has BSD make as make(1)
- Build verbosely to help debugging *FLAGS
- Ignore -lpthread underlinking (on WITHOUT_LLD_IS_LD) in unused samples

--- externals/unicorn/make.sh.orig	2018-01-04 00:41:12 UTC
+++ externals/unicorn/make.sh
@@ -112,7 +112,7 @@ if [ "$UNAME" = SunOS ]; then
   CC=gcc
 fi
 
-if [ -n "`echo "$UNAME" | grep BSD`" ]; then
+if [ -n "`echo "$UNAME" | grep -e DragonFly -e BSD`" ]; then
   MAKE=gmake
   PREFIX="${PREFIX-/usr/local}"
 fi
@@ -120,15 +120,15 @@ fi
 export CC INSTALL_BIN PREFIX PKGCFGDIR LIBDIRARCH LIBARCHS CFLAGS LDFLAGS
 
 case "$1" in
-  "" ) ${MAKE};;
+  "" ) ${MAKE} V=1 unicorn;;
   "asan" ) asan;;
   "install" ) install;;
   "uninstall" ) uninstall;;
-  "macos-universal" ) MACOS_UNIVERSAL=yes ${MAKE};;
-  "macos-universal-no" ) MACOS_UNIVERSAL=no ${MAKE};;
+  "macos-universal" ) MACOS_UNIVERSAL=yes ${MAKE} V=1 unicorn;;
+  "macos-universal-no" ) MACOS_UNIVERSAL=no ${MAKE} V=1 unicorn;;
   "cross-win32" ) build_cross i686-w64-mingw32;;
   "cross-win64" ) build_cross x86_64-w64-mingw32;;
-  "cross-android" ) CROSS=arm-linux-androideabi ${MAKE};;
+  "cross-android" ) CROSS=arm-linux-androideabi ${MAKE} V=1 unicorn;;
   "ios" ) build_iOS;;
   "ios_armv7" ) build_iOS armv7;;
   "ios_armv7s" ) build_iOS armv7s;;
