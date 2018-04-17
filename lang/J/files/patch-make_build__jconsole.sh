--- make/build_jconsole.sh.orig	2018-04-09 17:54:22 UTC
+++ make/build_jconsole.sh
@@ -1,9 +1,8 @@
 #!/usr/local/bin/bash
 # $1 is j32 or j64
-cd ~
-. jvars.sh
+. make/jvars.sh
 
-common=" -fPIC -O1 -Wextra "
+common=" -fPIC -Wextra "
 
 case $jplatform\_$1 in
 
@@ -27,6 +26,14 @@ darwin_j64)
 COMPILE="$common -DREADLINE -mmacosx-version-min=10.5"
 LINK=" -ledit -ldl -lncurses -mmacosx-version-min=10.5 -o jconsole "
 ;;
+freebsd_j32)
+COMPILE="$common -m32 -DREADLINE"
+LINK="-L${LOCALBASE}/lib -ledit -m32 -o jconsole "
+;;
+freebsd_j64)
+COMPILE="$common -DREADLINE"
+LINK="-L${LOCALBASE}/lib -ledit -o jconsole "
+;;
 *)
 echo no case for those parameters
 exit
