--- common.pro.orig	Mon Nov  3 09:40:15 2003
+++ common.pro	Mon Dec  1 03:16:47 2003
@@ -29,32 +29,12 @@
 # Now leaving these ON for general distribution as they DO have SOME effect 
 # (or at least they have in the past... see the README), and should be portable.
 # NB Switching on -funroll-loops causes some versions of gcc to segv
-QMAKE_CXXFLAGS_RELEASE -= -O2
-QMAKE_CXXFLAGS_RELEASE += -O3 -fomit-frame-pointer -ffast-math 
 
 ##################
 # Architecture specific optimisations
 # The following architecture options make the compiled executables less portable.
 # (On a different setup you may need to change what's subtracted out of the flags.)
 # NB -march=X implies -mcpu=X... no need to specify both the same
-
-contains(CONFIG_OPTS, p4 ){ 
-  QMAKE_CXXFLAGS_RELEASE -= -march=i386 -mcpu=i686
-  QMAKE_CXXFLAGS_RELEASE += -march=pentium4 -mfpmath=sse -msse2
-  BUILD_INFO+= Pentium4
-}
-
-contains(CONFIG_OPTS, p3 ){
-  QMAKE_CXXFLAGS_RELEASE -= -march=i386 -mcpu=i686
-  QMAKE_CXXFLAGS_RELEASE += -march=pentium3 -mfpmath=sse -msse
-  BUILD_INFO+= Pentium3  
-}
-
-contains(CONFIG_OPTS, xp ){
-  QMAKE_CXXFLAGS_RELEASE -= -march=i386 -mcpu=i686
-  QMAKE_CXXFLAGS_RELEASE += -march=athlon-xp -mfpmath=sse -msse
-  BUILD_INFO+= Athlon-XP
-}
 
 ##################
 # Optimisation insanity
