--- cplus2/unix.mk.orig	Sat Nov 20 22:27:41 1999
+++ cplus2/unix.mk	Sat Jan 18 01:55:19 2003
@@ -11,16 +11,16 @@
 
 #CC sets the name of the compiler to use (cc, gcc, etc)
 #You will have to change this to suit your system
-#CC             = g++
+CC             = ${CXX}
 
 AR              = ar
 CFLAGS          = -g
 DOS2UNIX        = ../dos2unix.sh
 
-%.o: %.cpp
+*.o: *.cpp
 		$(CC) -c $(CFLAGS) $< -o $@
 
-%.o: %.cxx
+*.o: *.cxx
 		$(CC) -c $(CFLAGS) $< -o $@
 
 all:            cr_lib.a
@@ -45,4 +45,7 @@
 clean:
 		\rm -f *.o
 		\rm -f *.a
+
+
+
 
