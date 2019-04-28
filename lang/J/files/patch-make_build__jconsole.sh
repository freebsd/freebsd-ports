--- make/build_jconsole.sh.orig	2019-01-06 17:19:19 UTC
+++ make/build_jconsole.sh
@@ -1,6 +1,6 @@
 #!/usr/local/bin/bash
 # $1 is j32 or j64
-cd ~
+. make/jvars.sh
 
 common=" -fPIC -O1 -Wextra -Wno-unused-parameter "
 
@@ -29,6 +29,14 @@ LINK=" -ledit -ldl -lncurses -m32 -mmacosx-version-min
 darwin_j64)
 COMPILE="$common -DREADLINE -mmacosx-version-min=10.5"
 LINK=" -ledit -ldl -lncurses -mmacosx-version-min=10.5 -o jconsole "
+;;
+freebsd_j32)
+COMPILE="$common -m32 -DREADLINE"
+LINK="-L${LOCALBASE}/lib -ledit -m32 -o jconsole "
+;;
+freebsd_j64)
+COMPILE="$common -DREADLINE"
+LINK="-L${LOCALBASE}/lib -ledit -o jconsole "
 ;;
 *)
 echo no case for those parameters
