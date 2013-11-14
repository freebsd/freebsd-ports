--- build.sh.orig
+++ build.sh
@@ -26,10 +26,6 @@
   esac
 done
 
-CC="gcc"
-LINKER="gcc"
-COMP_FLAGS="-w -O3 -fno-strict-aliasing$extraBuildArgs"
-LINK_FLAGS=""
 # platform detection
 ucpu=`uname -m`
 uos=`uname`
