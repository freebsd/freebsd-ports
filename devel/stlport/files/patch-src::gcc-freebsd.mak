--- src/gcc-freebsd.mak.orig	Fri Jan 16 08:25:37 2004
+++ src/gcc-freebsd.mak	Sat Nov  6 15:40:14 2004
@@ -5,8 +5,8 @@
 #
 # compiler
 #
-CC = gcc -pthread
-CXX = c++ -pthread -fexceptions
+CC += $(PTHREAD_CFLAGS) -D_REENTRANT
+CXX += $(PTHREAD_CFLAGS) -D_REENTRANT -fexceptions
 
 #
 # Basename for libraries
@@ -19,7 +19,7 @@
 #
 LINK=ar cr
 # 2.95 flag
-DYN_LINK=c++ -pthread -fexceptions -shared -o
+DYN_LINK=$(CXX) $(PTHREAD_LIBS) -fexceptions -shared -o
 
 OBJEXT=o
 DYNEXT=so
@@ -41,8 +41,8 @@
 
 CXXFLAGS_COMMON = -I${STLPORT_DIR} ${WARNING_FLAGS}
 
-CXXFLAGS_RELEASE_static = $(CXXFLAGS_COMMON) -O2
-CXXFLAGS_RELEASE_dynamic = $(CXXFLAGS_COMMON) -O2 -fPIC
+CXXFLAGS_RELEASE_static = $(CXXFLAGS_COMMON) $(CXXFLAGS)
+CXXFLAGS_RELEASE_dynamic = $(CXXFLAGS_COMMON) $(CXXFLAGS) -fPIC
 
 CXXFLAGS_DEBUG_static = $(CXXFLAGS_COMMON) -O -g
 CXXFLAGS_DEBUG_dynamic = $(CXXFLAGS_COMMON) -O -g -fPIC
