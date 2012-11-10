--- cplus2/unix.mk.orig	1999-11-21 15:27:41.000000000 +0900
+++ cplus2/unix.mk	2010-01-26 03:46:07.000000000 +0900
@@ -11,16 +11,16 @@
 
 #CC sets the name of the compiler to use (cc, gcc, etc)
 #You will have to change this to suit your system
-#CC             = g++
+CC             = ${CXX}
 
 AR              = ar
-CFLAGS          = -g
+CFLAGS          = ${CXXFLAGS}
 DOS2UNIX        = ../dos2unix.sh
 
-%.o: %.cpp
+.cpp.o:
 		$(CC) -c $(CFLAGS) $< -o $@
 
-%.o: %.cxx
+.cxx.o:
 		$(CC) -c $(CFLAGS) $< -o $@
 
 all:            cr_lib.a
@@ -46,3 +46,6 @@
 		\rm -f *.o
 		\rm -f *.a
 
+
+
+
