--- make/unix_gcc.mk.orig	Fri Jul 28 11:54:11 2000
+++ make/unix_gcc.mk	Sat Sep 28 21:55:53 2002
@@ -30,19 +30,6 @@
 #LD = ${GCCPATH}/gcc
 #CPP = ${GCCPATH}/g++ -E ${DEPINC}
 
-ifdef freebsd
-GCCPATH=	/usr
-GCC=		cc
-ifneq "${freebsd}" "40"
-ifneq "${freebsd}" "50"
-GCCBASE=	/usr/local
-GCCTARGET=	i386-unknown-freebsd3.0
-GCCVER=		egcs-2.91.62
-GCCPATH=	${GCCBASE}/lib/gcc-lib/${GCCTARGET}/${GCCVER}
-GCC=		egcc
-endif
-endif
-endif
 ifdef linux
 GCCBASE=	/usr
 GCCTARGET=	i686-pc-linux-gnu
@@ -51,17 +38,15 @@
 GCC=		gcc
 endif
 
-CC   = ${GCC} -pipe
-CXX  = ${GCC} -x c++ -pipe
 AS   = as
-LD   = cc -pthread
-CPP  = ${GCC} -x c++ -E ${DEPINC}
+LD   = $(CC) -pthread
+CPP  = $(CC) -x c++ -E ${DEPINC}
 INSTALL = install -c
 
 
 CPPFLAGS += -Dq_unix
 
-CPPFLAGS += -I/usr/X11R6/include -I${GCCPATH}/include/g++
+CPPFLAGS += -I/usr/X11R6/include
 CPPFLAGS += -I/usr/local/include
 
 ifdef linux
@@ -70,7 +55,7 @@
 
 
 #CXXFLAGS = -ansi -Wall -g -fguiding-decls -D_THREAD_SAFE
-CXXFLAGS = -ansi -Wall -gdwarf-2 -D_THREAD_SAFE
+CXXFLAGS += -ansi -Wall -gdwarf-2 -D_THREAD_SAFE
 
 ifdef linux
     CXXFLAGS += -D_SVID_SOURCE -D_BSD_SOURCE
@@ -80,17 +65,9 @@
     CPPFLAGS += -DDEBUG
 endif
 
-ifdef noopt
-    CXXFLAGS += -O0
-else
-    CXXFLAGS += -O2
-endif
-
 CFLAGS = ${CXXFLAGS}
 
-ifdef freebsd
-    DEPINC = -I${GCCPATH}/include/g++
-else
+ifndef freebsd
     DEPINC = -I${GCCPATH}/include/g++ -I${GCCPATH}
 endif
 
@@ -115,10 +92,6 @@
 
 ifdef linux
     EXTRALIBS = -ldl
-endif
-
-ifneq "${freebsd}" "40"
-    RUNPATH= -Wl,-rpath=${GCCPATH} -L${GCCPATH}
 endif
 
 # assemble a file
