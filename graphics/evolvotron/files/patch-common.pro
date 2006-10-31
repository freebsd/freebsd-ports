--- common.pro.orig	Wed Nov  9 13:50:09 2005
+++ common.pro	Wed Nov  9 13:51:25 2005
@@ -20,8 +20,6 @@
 # Now leaving these ON for general distribution as they DO have SOME effect 
 # (or at least they have in the past... see the README), and should be portable.
 # NB Switching on -funroll-loops causes some versions of gcc to segv
-QMAKE_CXXFLAGS_RELEASE -= -O2
-QMAKE_CXXFLAGS_RELEASE += -O3 -fomit-frame-pointer -ffast-math 
 
 ##################
 # Architecture specific optimisations
@@ -29,23 +27,6 @@
 # (On a different setup you may need to change what is subtracted out of the flags.)
 # NB -march=X implies -mcpu=X... no need to specify both the same
 
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
