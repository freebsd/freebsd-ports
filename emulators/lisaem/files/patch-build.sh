--- build.sh.orig	2007-07-10 05:23:23.000000000 +0200
+++ build.sh	2007-09-25 08:25:06.000000000 +0200
@@ -426,8 +426,8 @@
 then
  # many thanks to David Cecchin for finding the unicode issues fixed below.
  WXCONFIGFLAGS=`wx-config  --cppflags --unicode=no `
- CFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- CXXFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
+ CFLAGS+=" -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
+ CXXFLAGS+=" -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
  LINKOPTS="`wx-config $STATIC  --unicode=no --libs --linkdeps --cppflags`"
  [ -z "$CC" ] && CC=gcc
  [ -z "$CXX" ] && CXX=g++
@@ -768,7 +768,7 @@
 #echo $CXX $GCCSTATIC  $WITHDEBUG -o lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS
 if [ -z "$WITHWXUI" ]
 then
-$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS 2>&1  | head -20
+$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS 2>&1  | head -20
 fi
 
 ## if [ -n "$WITHWXUI" ]
