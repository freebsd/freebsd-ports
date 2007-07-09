--- build.sh.orig	Thu Jul  5 14:49:15 2007
+++ build.sh	Thu Jul  5 14:51:42 2007
@@ -422,8 +422,8 @@
 then
 
  WXCONFIGFLAGS=`wx-config  --cppflags`
- CFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- CXXFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
+ CFLAGS+=" -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
+ CXXFLAGS+=" -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
  LINKOPTS="`wx-config $STATIC  --libs --linkdeps --cppflags`"
  [ -z "$CC" ] && CC=gcc
  [ -z "$CXX" ] && CXX=g++
@@ -759,7 +759,7 @@
 #echo $CXX $GCCSTATIC  $WITHDEBUG -o lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS
 if [ -z "$WITHWXUI" ]
 then
-$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS 2>&1  | head -20
+$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS 2>&1  | head -20
 fi
 
 ## if [ -n "$WITHWXUI" ]
