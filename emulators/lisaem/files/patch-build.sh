--- build.sh.orig	2007-12-11 15:26:12.000000000 +0100
+++ build.sh	2007-12-13 23:24:15.000000000 +0100
@@ -469,8 +469,8 @@
     which wx-config
     exit 3
  fi
- CFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- CXXFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
+ CFLAGS+=" -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
+ CXXFLAGS+=" -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
  LINKOPTS="`wx-config $STATIC  $WITHUNICODE  --libs --linkdeps --cppflags`"
  if [ -z "$LINKOPTS" ]
  then
@@ -840,7 +840,7 @@
 #echo $CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS
 if [ -z "$WITHWXUI" ]
 then
-$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS 2>&1  | head -20
+$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS 2>&1  | head -20
 fi
 
 if [ -f ../bin/lisaem ]
