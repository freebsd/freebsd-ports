--- ./build.sh.orig	2007-12-11 15:26:12.000000000 +0100
+++ ./build.sh	2010-07-14 12:13:45.217194209 +0200
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 #### Edit these options for your system
 
@@ -44,7 +44,7 @@
 
 if [ -z "$CYGWIN" ];
 then
- [ "`uname`" == "CYGWIN_NT-5.0" ] && CYGWIN="`uname`"
+ [ "`uname`" = "CYGWIN_NT-5.0" ] && CYGWIN="`uname`"
 fi
 
 
@@ -154,14 +154,14 @@
 else
 
 WXVER=0
-case "`wx-config --version`" in
+case "`%%WX_CONFIG%% --version`" in
   2.9*|3*)
         echo WARNING: wxWidgets versions higher than 2.8 have not been tested.
         echo It might work if they are compiled with backwards compatibility.
         ;;
   2.8*) ;;
   *)    echo Could not find wxWidgets 2.8.0 or higher.
-        echo Please install it and ensure that wx-config is in the path
+        echo Please install it and ensure that %%WX_CONFIG%% is in the path
         exit 1
   ;;
 esac
@@ -169,7 +169,7 @@
 
 fi
 #$CYGWIN is pre-set.  Cache $DARWIN so we don't have to call uname over and over.
-[ "`uname`" == "Darwin" ] && DARWIN="Darwin"
+[ "`uname`" = "Darwin" ] && DARWIN="Darwin"
 
 # not needed on OS X
 if [ -z "$DARWIN" ]
@@ -190,8 +190,8 @@
 # purpose of this is to avoid errors on systems that have only unicode.
 if [ -z "$CYGWIN" ]
 then
-  WXREL="`wx-config --release`"
-  if [ -n "`wx-config --list | grep $WXREL | grep unicode`" ]
+  WXREL="`%%WX_CONFIG%% --release`"
+  if [ -n "`%%WX_CONFIG%% --list | grep $WXREL | grep unicode`" ]
   then
     WITHUNICODE="--unicode=yes"
   fi
@@ -210,8 +210,8 @@
          PREFIX="/cygdrive/c/Program Files/Sunder.NET/LisaEm"
          PREFIXLIB="/cygdrive/c/Program Files/Sunder.NET/LisaEm"
       else
-         PREFIX="/usr/local/bin"
-         PREFIXLIB="/usr/local/share/"
+         PREFIX="%%PREFIX%%/bin"
+         PREFIXLIB="%%PREFIX%%/share/"
       fi
   fi
 fi
@@ -230,11 +230,11 @@
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
@@ -379,8 +379,8 @@
                        (OS X only, doesn't work properly elsewhere)
 --without-rawbitmap    Disables Raw bitmap access, uses wxImage::SetRGB instead
 					   (default for non-OS X)
---with-unicode         Ask wx-config for a unicode build (might not yet work)
---without-unicode      Ask wx-config for a non-unicode build (default)
+--with-unicode         Ask %%WX_CONFIG%% for a unicode build (might not yet work)
+--without-unicode      Ask %%WX_CONFIG%% for a non-unicode build (default)
 
 Environment Variables you can pass:
 
@@ -462,20 +462,20 @@
 then
  # many thanks to David Cecchin for finding the unicode issues fixed below.
 
- WXCONFIGFLAGS=`wx-config  --cppflags $WITHUNICODE `
+ WXCONFIGFLAGS=`%%WX_CONFIG%%  --cppflags $WITHUNICODE `
  if [ -z "$WXCONFIGFLAGS" ]
  then
-    echo wx-config has failed, or returned an error.  Ensure that it exists in your path.
-    which wx-config
+    echo %%WX_CONFIG%% has failed, or returned an error.  Ensure that it exists in your path.
+    which %%WX_CONFIG%%
     exit 3
  fi
- CFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- CXXFLAGS="-I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS $WITHOPTIMIZE $WITHDEBUG"
- LINKOPTS="`wx-config $STATIC  $WITHUNICODE  --libs --linkdeps --cppflags`"
+ CFLAGS="$CFLAGS -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
+ CXXFLAGS="$CXXFLAGS -I. -I../include -I../cpu68k -I../wxui $WXCONFIGFLAGS"
+ LINKOPTS="`%%WX_CONFIG%% $STATIC  $WITHUNICODE  --libs --linkdeps --cppflags`"
  if [ -z "$LINKOPTS" ]
  then
-    echo wx-config has failed, or returned an error.  Ensure that it exists in your path.
-    which wx-config
+    echo %%WX_CONFIG%% has failed, or returned an error.  Ensure that it exists in your path.
+    which %%WX_CONFIG%%
     exit 3
  fi
 
@@ -840,7 +840,7 @@
 #echo $CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS
 if [ -z "$WITHWXUI" ]
 then
-$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS $SYSLIBS 2>&1  | head -20
+$CXX $GCCSTATIC $WITHTRACE $WITHDEBUG -o ../bin/lisaem  $LIST ../generator/libgenerator.a ../cpu68k/lib68k.a $LINKOPTS 2>&1  | head -20
 fi
 
 if [ -f ../bin/lisaem ]
@@ -960,8 +960,8 @@
 then
 
   echo "Freshly compiled `du -sh lisaem`"
-  strip lisaem${EXT}
-  echo "Stripped `du -sh lisaem`"
+# strip lisaem${EXT}
+# echo "Stripped `du -sh lisaem`"
 
   # compress it if upx exists.
   if [ -z "$WITHOUTUPX"              ]; then
