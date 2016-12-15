--- build.sh.orig	2016-12-13 16:14:36 UTC
+++ build.sh
@@ -26,10 +26,6 @@
   esac
 done
 
-CC="gcc"
-LINKER="gcc"
-COMP_FLAGS="${CPPFLAGS:-} ${CFLAGS:-} -w -O3 -fno-strict-aliasing$extraBuildArgs"
-LINK_FLAGS="${LDFLAGS:-} "
 PS4=""
 # platform detection
 ucpu=`uname -m`
