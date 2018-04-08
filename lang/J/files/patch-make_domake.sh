--- make/domake.sh.orig	2017-11-02 18:50:23 UTC
+++ make/domake.sh
@@ -3,8 +3,7 @@
 # run by build_jconsole and build_libj
 # $1 is j32 or j64
 
-cd ~
-. jvars.sh
+. make/jvars.sh
 
 echo $TARGET
 echo $COMPILE
@@ -12,7 +11,7 @@ echo $LINK
 mkdir -p $jbld/jout/$TARGET/$1/blis
 cd $jbld/jout/$TARGET/$1
 
-make -f $jmake/makefile
+gmake -f $jmake/makefile
 
 if [ $1 = "j64avx" ] ; then
  if [ $TARGET = "libj.dylib" ] ; then
