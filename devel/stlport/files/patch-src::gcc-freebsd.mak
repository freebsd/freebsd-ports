--- src/gcc-freebsd.mak.orig	Tue Nov 27 02:17:56 2001
+++ src/gcc-freebsd.mak	Tue Jun 25 07:30:55 2002
@@ -5,8 +5,8 @@
 #
 # compiler
 #
-CC = gcc -pthread
-CXX = c++ -pthread -fexceptions
+CC+= ${PTHREAD_CFLAGS} -D_REENTRANT
+CXX+= ${PTHREAD_CFLAGS} -D_REENTRANT -fexceptions
 
 #
 # Basename for libraries
@@ -19,7 +19,7 @@
 #
 LINK=ar cr
 # 2.95 flag
-DYN_LINK=c++ -pthread -fexceptions -shared -o
+DYN_LINK=$(CXX) ${PTHREAD_LIBS} -shared -o
 
 OBJEXT=o
 DYNEXT=so
@@ -41,8 +41,8 @@
 
 CXXFLAGS_COMMON = -I${STLPORT_DIR} ${WARNING_FLAGS}
 
-CXXFLAGS_RELEASE_static = $(CXXFLAGS_COMMON) -O2
-CXXFLAGS_RELEASE_dynamic = $(CXXFLAGS_COMMON) -O2 -fPIC
+CXXFLAGS_RELEASE_static = $(CXXFLAGS_COMMON) ${CXXFLAGS}
+CXXFLAGS_RELEASE_dynamic = $(CXXFLAGS_COMMON) ${CXXFLAGS} -fPIC
 
 CXXFLAGS_DEBUG_static = $(CXXFLAGS_COMMON) -O -g
 CXXFLAGS_DEBUG_dynamic = $(CXXFLAGS_COMMON) -O -g -fPIC
