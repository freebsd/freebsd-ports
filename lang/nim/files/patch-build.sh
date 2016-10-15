--- build.sh.orig	2016-10-08 02:10:59 UTC
+++ build.sh
@@ -26,10 +26,6 @@ do
   esac
 done
 
-CC="gcc"
-LINKER="gcc"
-COMP_FLAGS="${CPPFLAGS:-} ${CFLAGS:-} -w -O3 -fno-strict-aliasing$extraBuildArgs"
-LINK_FLAGS="${LDFLAGS:-} "
 PS4=""
 # platform detection
 ucpu=`uname -m`
