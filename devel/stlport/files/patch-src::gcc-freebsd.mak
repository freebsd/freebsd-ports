--- src/gcc-freebsd.mak.orig	Fri Jun  7 10:08:47 2002
+++ src/gcc-freebsd.mak	Fri Jun  7 10:12:33 2002
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
