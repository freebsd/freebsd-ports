--- Makefile.inc.orig	Mon Jan 19 16:03:37 2004
+++ Makefile.inc	Tue Feb  3 21:01:10 2004
@@ -2,7 +2,7 @@
 
 # Where to install stuff
 
-MOSMLHOME=${HOME}/mosml
+#MOSMLHOME=${HOME}/mosml
 
 # Various utility programs
 INSTALL_PROGRAM=cp
@@ -15,7 +15,7 @@
 
 ADDPRIMS=dynlib.c
 ADDOBJS=dynlib.o
-ADDRUNLIBS=-ldl
+ADDRUNLIBS=
 ADDRUNCFLAGS=
 ADDDYNLIBCFLAGS=
 
@@ -45,13 +45,13 @@
 
 # For NetBSD, use:
 # ------------------------
-# CPP=/usr/bin/cpp -P -traditional -Dunix -Umsdos
-# STRIP=/usr/bin/strip
-# ADDRUNCFLAGS=-fPIC
-# ADDDYNLIBCFLAGS=-fPIC
-# INSTALL_PROGRAM=${BSD_INSTALL_PROGRAM}
-# INSTALL_SCRIPT=${BSD_INSTALL_SCRIPT}
-# INSTALL_DATA=${BSD_INSTALL_DATA}
+CPP=/usr/bin/cpp -P -traditional -Dunix -Umsdos
+STRIP=/usr/bin/strip
+ADDRUNCFLAGS=-fPIC
+ADDDYNLIBCFLAGS=-fPIC
+INSTALL_PROGRAM=${BSD_INSTALL_PROGRAM}
+INSTALL_SCRIPT=${BSD_INSTALL_SCRIPT}
+INSTALL_DATA=${BSD_INSTALL_DATA}
 
 # For Solaris 2 (not SunOS 4), use:
 # ---------------------------------
@@ -113,13 +113,16 @@
 # INCDIR contains the runtime system header files (for compiling dynlibs)
 # DOCDIR contains documentation
 
-BINDIR=${MOSMLHOME}/bin
-LIBDIR=${MOSMLHOME}/lib
-INCDIR=${MOSMLHOME}/include
-DOCDIR=${MOSMLHOME}/doc
-TOOLDIR=${MOSMLHOME}/tools
-# LIBDIR=${MOSMLHOME}/lib/moscow_ml
-# TOOLDIR=${MOSMLHOME}/libexec/moscow_ml
+#BINDIR=${MOSMLHOME}/bin
+BINDIR=${PREFIX}/bin
+#LIBDIR=${MOSMLHOME}/lib
+LIBDIR=${PREFIX}/lib/mosml
+#INCDIR=${MOSMLHOME}/include
+INCDIR=${PREFIX}/include/mosml
+#DOCDIR=${MOSMLHOME}/doc
+DOCDIR=${DOCSDIR}
+#TOOLDIR=${MOSMLHOME}/tools
+TOOLDIR=${PREFIX}/libexec/mosml
 
 CAMLRT=../runtime
 
@@ -142,7 +145,7 @@
 # For cross-compiling to Win 32 (from Linux) (development only)
 # CPP=/lib/cpp -P -traditional -Umsdos -Uunix -Dwin32
 
-CC=gcc
+CC ?= gcc
 
 .SUFFIXES :
 .SUFFIXES : .sml .sig .ui .uo .mlp .lex .c .o
