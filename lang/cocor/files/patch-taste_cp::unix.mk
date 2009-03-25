--- taste_cp/unix.mk.orig	2009-03-25 13:31:23.000000000 +0100
+++ taste_cp/unix.mk	2009-03-25 13:33:00.000000000 +0100
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
@@ -38,7 +38,7 @@
 		$(CC) $(CFLAGS) -otaste taste.o tl.o tc.o\
                                         tastes.o tastep.o $(LIB)
 
-tastep.o:       taste.atg
+tastep.o taste.o:       taste.atg
 		$(COCOR) taste.atg
 		$(CC) $(CFLAGS) -c taste.c?? tastep.c?? tastes.c??
 
@@ -46,7 +46,7 @@
 		$(CC) $(CFLAGS) -opretty pretty.o prettypr.o \
                                          prettys.o prettyp.o $(LIB)
 
-prettyp.o:      pretty.atg
+prettyp.o pretty.o:      pretty.atg
 		$(COCOR) pretty.atg
 		$(CC) $(CFLAGS) -c pretty.c?? prettyp.c?? prettys.c??
 
@@ -54,7 +54,7 @@
 		$(CC) $(CFLAGS) -oxref xref.o crossref.o \
                                        xrefs.o xrefp.o $(LIB)
 
-xrefp.o:        xref.atg
+xrefp.o xref.o:        xref.atg
 		$(COCOR) xref.atg
 		$(CC) $(CFLAGS) -c xref.c?? xrefp.c?? xrefs.c??
 
