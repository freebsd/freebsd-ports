--- taste_cp/unix.mk.orig	Sat Jan 18 01:58:29 2003
+++ taste_cp/unix.mk	Sat Jan 18 01:59:37 2003
@@ -8,17 +8,17 @@
 
 #CC sets the name of the compiler to use (cc, gcc, etc)
 #You will have to change this to suit your system
-#CC             = g++
+CC             = ${CXX}
 
 CFLAGS          = -g -I../cplus2
 COCOR           = ../cocor
 DOS2UNIX        = ../dos2unix.sh
 LIB             = ../cplus2/cr_lib.a
 
-%.o: %.cpp
+*.o: *.cpp
 		$(CC) -c $(CFLAGS) $< -o $@
 
-%.o: %.cxx
+*.o: *.cxx
 		$(CC) -c $(CFLAGS) $< -o $@
 
 all:            taste pretty xref
