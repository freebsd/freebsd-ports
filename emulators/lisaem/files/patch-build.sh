--- build.sh.orig	2015-09-03 19:56:33 UTC
+++ build.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 #### Edit these options for your system
 
@@ -46,7 +46,7 @@ done
 
 if [ -z "$CYGWIN" ];
 then
- [ "`uname`" == "CYGWIN_NT-5.0" ] && CYGWIN="`uname`"
+ [ "`uname`" = "CYGWIN_NT-5.0" ] && CYGWIN="`uname`"
 fi
 
 
@@ -121,9 +121,9 @@ WITHBLITS="-DUSE_RAW_BITMAP_ACCESS"
    export RCINCS="--include-dir=`cygpath -wp ${WXDEV}/include/common` "
    export DEFINES="-D__WXMSW__ -D__GNUWIN32__ -D__WIN95__ -D __WIN32__"
    export CXXINCS="-I. -I ..\include -I ..\cpu68k -I ..\\wxui -I `cygpath -wp ${MINGW}/include`  -I `cygpath -wp ${MINGCPP}/backward`  -I `cygpath -wp ${MINGCPP}/mingw32`  -I `cygpath -wp ${MINGCPP}`  -I `cygpath -wp ${WXDEV}/include`  -I `cygpath -wp ${WXDEV}/`  -I `cygpath -wp ${WXDEV}/include/common/wx/msw`  -I `cygpath -wp ${WXDEV}/include/common/wx/generic`  -I `cygpath -wp ${WXDEV}/include/common/wx/fl`  -I `cygpath -wp ${WXDEV}/include/common/wx/gizmos`  -I `cygpath -wp ${WXDEV}/include/common/wx/html`  -I `cygpath -wp ${WXDEV}/include/common/wx/mmedia`  -I `cygpath -wp ${WXDEV}/include/common/wx/net`  -I `cygpath -wp ${WXDEV}/include/common/wx/ogl`  -I `cygpath -wp ${WXDEV}/include/common/wx/plot`  -I `cygpath -wp ${WXDEV}/include/common/wx/protocol`  -I `cygpath -wp ${WXDEV}/include/common/wx/stc`  -I `cygpath -wp ${WXDEV}/include/common/wx/svg`  -I `cygpath -wp ${WXDEV}/include/common/wx/xml`  -I `cygpath -wp ${WXDEV}/include/common/wx/xrc`  -I `cygpath -wp ${WXDEV}/include/common/wx`  -I `cygpath -wp ${WXDEV}/include/common`"
-   export CXXFLAGS="${CXXINCS} ${DEFINES}"
+   export CXXFLAGS="${CXXFLAGS} ${CXXINCS} ${DEFINES}"
    export CXXFLAGS="-Wno-write-strings ${CXXINCS} ${DEFINES}"  #2015.08.30 allow GCC 4.6.3 to ignore constant violation
-   export CFLAGS="${INCS} ${DEFINES} -fno-exceptions -fno-pcc-struct-return -fstrict-aliasing $WARNINGS -Wno-format -Wno-unused -D__WXMSW__ -D__GNUWIN32__ -D__WIN95__   -fexpensive-optimizations -O3"
+   export CFLAGS="${CFLAGS} ${INCS} ${DEFINES} -fno-exceptions -fno-pcc-struct-return -fstrict-aliasing $WARNINGS -Wno-format -Wno-unused -D__WXMSW__ -D__GNUWIN32__ -D__WIN95__"
    export GPROF=gprof.exe
    export RM="rm -f"
    export LINK=g++.exe
@@ -172,7 +172,7 @@ esac
 
 fi
 #$CYGWIN is pre-set.  Cache $DARWIN so we don't have to call uname over and over.
-[ "`uname`" == "Darwin" ] && DARWIN="Darwin"
+[ "`uname`" = "Darwin" ] && DARWIN="Darwin"
 
 
 # not needed on OS X
@@ -234,11 +234,11 @@ fi
 # if the object is older than the source, it will return true.
 ##############################################################################
 
-function NEEDED()
+NEEDED()
 {
  if [ -f $2 ]
  then
-   [ "`ls -tr $2 $1 2>/dev/null| tail -1`" == "$1" ] && return 0
+   [ "`ls -tr $2 $1 2>/dev/null| tail -1`" = "$1" ] && return 0
    return 1
  fi
  return 0
@@ -399,7 +399,7 @@ exit 1
 fi
 
 # create built by info and license
-BUILTBY="\"Compiled on `date` by $LOGNAME@`uname -n`  (`uname -v `)\n options:$WITHBLITS $WITHDEBUG $WITHTRACE $WITHUNICODE\""
+BUILTBY="\"options:$WITHBLITS $WITHDEBUG $WITHTRACE $WITHUNICODE\""
 echo "#define BUILTBY $BUILTBY" >./include/built_by.h
 echo -n "#define LICENSE "    >>./include/built_by.h
 cat LICENSE | sed 's/^/"/g' | sed 's/$/\\n"      \\/g' >>./include/built_by.h
@@ -475,9 +475,9 @@ then
  fi
 #2015.08.31 
  #CFLAGS="-Wwrite-strings -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- CFLAGS="-Wno-write-strings -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- CXXFLAGS="-Wno-write-strings -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- LINKOPTS="`wx-config $STATIC  $WITHUNICODE  --libs --linkdeps --cppflags`"
+ CFLAGS="$CFLAGS -Wno-write-strings -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
+ CXXFLAGS="$CXXFLAGS -Wno-write-strings -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
+ LINKOPTS="$LDFLAGS `wx-config $STATIC  $WITHUNICODE  --libs --linkdeps --cppflags`"
  if [ -z "$LINKOPTS" ]
  then
     echo wx-config has failed, or returned an error.  Ensure that it exists in your path.
@@ -493,7 +493,7 @@ fi
 ###########################################################################
 
 # Has the configuration changed since last time? if so we may need to do a clean build.
-[ -f .last-opts ] && source .last-opts
+[ -f .last-opts ] && . .last-opts
 
 needclean=0
 #debug and tracelog changes affect the whole project, so need to clean it all
@@ -663,7 +663,6 @@ then
   $CC $CFLAGS $LDFLAGS -o ../bin/lisadiskinfo lisadiskinfo.c libdc42.o || exit 1
   if [ -z "$WITHDEBUG" ]
   then
-    strip ../bin/lisadiskinfo${EXT}
     if  [ -z "$WITHOUTUPX"                 ]; then
      if [ -x "`which upx 2>/dev/null`"     ]; then upx --best ../bin/lisadiskinfo${EXT} ; fi
     fi
@@ -682,7 +681,6 @@ then
   $CC $CFLAGS -o ../bin/lisafsh-tool lisafsh-tool.c libdc42.o || exit 1
   if [ -z "$WITHDEBUG" ]
   then
-    strip ../bin/lisafsh-tool${EXT}
     if  [ -z "$WITHOUTUPX"                 ]; then
      if [ -x "`which upx 2>/dev/null`"     ]; then upx --best ../bin/lisafsh-tool${EXT} ; fi
     fi
@@ -737,7 +735,7 @@ if [ "$VSTATIC" -gt 0 ]; then DEPS=1; else DEPS=0; fi
 if [ "$DEPS" -gt 0 ]
 then
   echo "  Compiling lisaem_static_resources.cpp..."
-  $CXX $CFLAGS -c lisaem_static_resources.cpp -o lisaem_static_resources.o || exit 1
+  $CXX $CXXFLAGS -c lisaem_static_resources.cpp -o lisaem_static_resources.o || exit 1
 fi
 LIST="$LIST lisaem_static_resources.o"
 
@@ -803,7 +801,7 @@ do
   if NEEDED ${i}.cpp ${i}.o
   then
      echo "  Compiling ${i}.cpp..."
-     $CXX -W $WARNINGS $WITHDEBUG $WITHTRACE $WITHBLITS $CFLAGS -c ${i}.cpp -o ${i}.o || exit 1
+     $CXX -W $WARNINGS $WITHDEBUG $WITHTRACE $WITHBLITS $CXXFLAGS -c ${i}.cpp -o ${i}.o || exit 1
   fi
 done
 
@@ -908,7 +906,6 @@ then
 	done
 	cp $RESCPYLIST LisaEm.app/Contents/Resources/   || exit 1
 
-    [ -z "$WITHDEBUG" ] && strip ./lisaem
     chmod 755 lisaem
     mv lisaem LisaEm
     mv LisaEm LisaEm.app/Contents/MacOS/
@@ -989,8 +986,6 @@ if [ -z "$WITHDEBUG" ]
 then
 
   echo "Freshly compiled `du -sh lisaem`"
-  strip lisaem${EXT}
-  echo "Stripped `du -sh lisaem`"
 
   # compress it if upx exists.
   if [ -z "$WITHOUTUPX"              ]; then
