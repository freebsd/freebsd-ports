--- common.pro.orig	Mon Nov  3 09:40:15 2003
+++ common.pro	Mon Dec  1 03:16:47 2003
@@ -29,8 +29,6 @@
 # Now leaving these ON for general distribution as they DO have SOME effect 
 # (or at least they have in the past... see the README), and should be portable.
 
-QMAKE_CXXFLAGS_RELEASE -= -O2
-QMAKE_CXXFLAGS_RELEASE += -O3 -fomit-frame-pointer -funroll-loops -ffast-math 
 
 ##################
 # Architecture specific optimisations
@@ -38,23 +36,6 @@
 # (On a different setup you may need to change what's subtracted out of the flags.)
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
@@ -67,7 +48,7 @@
 #######################################
 # Version numbering.  This is ENTIRELY controlled by what is echoed by the VERSION script
 
-VERSION_NUMBER = $${system(../VERSION)}
+VERSION_NUMBER = $${system(./VERSION)}
 QMAKE_CXXFLAGS_RELEASE += '-DEVOLVOTRON_VERSION="$$VERSION_NUMBER"'
 QMAKE_CXXFLAGS_DEBUG   += '-DEVOLVOTRON_VERSION="$$VERSION_NUMBER"'
 QMAKE_CXXFLAGS_RELEASE += '-DEVOLVOTRON_BUILD="$$VERSION_NUMBER (Build options: $$BUILD_INFO Release)"'
