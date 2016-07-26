--- configuration.sh.orig	1994-06-23 12:14:46 UTC
+++ configuration.sh
@@ -72,6 +72,16 @@ case `uname -sr` in
      INCLUDEDIRS=
      LIBRARIES=
      AUDIO_INCLUDES='#include <sys/audioio.h>' ;;
+  FreeBSD*)
+     COMPILER='${CXX}'
+     if [ ${ARCH} = "i386" ]; then
+       COMPILERFLAGS='-DLINUX -DDAMN_INTEL_BYTE_ORDER'
+     else
+       COMPILERFLAGS='-DLINUX'
+     fi
+     INCLUDEDIRS=
+     LIBRARIES= 
+     AUDIO_INCLUDES='#include <sys/soundcard.h>' ;;
   Linux*)
      COMPILER=g++
      COMPILERFLAGS='-O2 -m486 -funroll-loops -DLINUX -DDAMN_INTEL_BYTE_ORDER'
@@ -95,4 +105,4 @@ if [ ! -f audio_includes.h ]; then
   echo $AUDIO_INCLUDES >audio_includes.h
 fi
 
-make all
+make maplay
