--- make/domake.sh.orig	2018-04-09 18:08:56 UTC
+++ make/domake.sh
@@ -3,8 +3,7 @@
 # run by build_jconsole and build_libj
 # $1 is j32 or j64
 
-cd ~
-. jvars.sh
+. make/jvars.sh
 
 echo $TARGET
 echo $COMPILE
@@ -12,5 +11,5 @@ echo $LINK
 mkdir -p $jbld/jout/$TARGET/$1
 cd $jbld/jout/$TARGET/$1
 
-make -f $jmake/makefile
+gmake -f $jmake/makefile
 cp $TARGET $jbld/$1/bin
