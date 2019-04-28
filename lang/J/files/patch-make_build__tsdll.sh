--- make/build_tsdll.sh.orig	2019-03-10 15:32:23 UTC
+++ make/build_tsdll.sh
@@ -1,9 +1,22 @@
 #!/usr/local/bin/bash
 # $1 is j32 or j64
-cd ~
+. make/jvars.sh
 
+compiler=${CC:0:3}
+
 common=" -fPIC -O1 -Werror -Wextra -Wno-unused-parameter"
 
+if [ "x$compiler" = x'gcc' ] ; then
+OVER_GCC_VER7=$(echo `$CC -dumpversion | cut -f1 -d.` \>= 7 | bc)
+if [ $OVER_GCC_VER7 -eq 1 ] ; then
+common="$common -Wno-implicit-fallthrough"
+fi
+OVER_GCC_VER8=$(echo `$CC -dumpversion | cut -f1 -d.` \>= 8 | bc)
+if [ $OVER_GCC_VER8 -eq 1 ] ; then
+common="$common -Wno-cast-function-type"
+fi
+fi
+
 case $jplatform\_$1 in
 
 linux_j32)
@@ -35,6 +48,16 @@ darwin_j64)
 TARGET=libtsdll.dylib
 COMPILE="$common "
 LINK=" -dynamiclib -o libtsdll.dylib "
+;;
+freebsd_j32)
+TARGET=libtsdll.so
+COMPILE="$common -m32 "
+LINK=" -shared -Wl,-soname,libtsdll.so  -m32 -o libtsdll.so "
+;;
+freebsd_j64)
+TARGET=libtsdll.so
+COMPILE="$common "
+LINK=" -shared -Wl,-soname,libtsdll.so -o libtsdll.so "
 ;;
 *)
 echo no case for those parameters
