--- make/build_tsdll.sh.orig	2018-02-24 19:49:42 UTC
+++ make/build_tsdll.sh
@@ -1,9 +1,8 @@
 #!/usr/local/bin/bash
 # $1 is j32 or j64
-cd ~
-. jvars.sh
+. make/jvars.sh
 
-common=" -fPIC -O1 -Werror -Wextra -Wno-unused-parameter"
+common=" -fPIC -Werror -Wextra -Wno-unused-parameter"
 
 case $jplatform\_$1 in
 
@@ -38,6 +37,16 @@ TARGET=libtsdll.dylib
 COMPILE="$common "
 LINK=" -dynamiclib -o libtsdll.dylib "
 ;;
+freebsd_j32)
+TARGET=libtsdll.so
+COMPILE="$common -m32 "
+LINK=" -shared -Wl,-soname,libtsdll.so  -m32 -o libtsdll.so "
+;;
+freebsd_j64)
+TARGET=libtsdll.so
+COMPILE="$common "
+LINK=" -shared -Wl,-soname,libtsdll.so -o libtsdll.so "
+;;
 *)
 echo no case for those parameters
 exit
