--- make/domake.sh.orig	2019-01-06 11:36:39 UTC
+++ make/domake.sh
@@ -15,7 +15,7 @@ if [ $1 = "j64nonavx" ] ; then
  avx=-nonavx
 fi 
 
-echo "building  $jbld/$targ/bin/$TARGET $avx"
+gmake -f $jmake/makefile
 echo "output in $jbld/$targ/bin/build_$TARGET$avx.txt"
 make -f $jmake/makefile >$jbld/$targ/bin/build_$TARGET$avx.txt 2>&1
 echo `egrep -w 'warning|error|note' $jbld/$targ/bin/build_$TARGET$avx.txt`
