--- Makefile.inc.orig	2004-01-19 15:03:37.000000000 +0000
+++ Makefile.inc
@@ -2,7 +2,6 @@
 
 # Where to install stuff
 
-MOSMLHOME=${HOME}/mosml
 
 # Various utility programs
 INSTALL_PROGRAM=cp
@@ -15,7 +14,7 @@ PERL=perl
 
 ADDPRIMS=dynlib.c
 ADDOBJS=dynlib.o
-ADDRUNLIBS=-ldl
+ADDRUNLIBS=
 ADDRUNCFLAGS=
 ADDDYNLIBCFLAGS=
 
@@ -45,13 +44,14 @@ DYNLD=ld -shared
 
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
+LD=${CC} -rdynamic
 
 # For Solaris 2 (not SunOS 4), use:
 # ---------------------------------
@@ -113,13 +113,11 @@ SHELL=/bin/sh
 # INCDIR contains the runtime system header files (for compiling dynlibs)
 # DOCDIR contains documentation
 
-BINDIR=${MOSMLHOME}/bin
-LIBDIR=${MOSMLHOME}/lib
-INCDIR=${MOSMLHOME}/include
-DOCDIR=${MOSMLHOME}/doc
-TOOLDIR=${MOSMLHOME}/tools
-# LIBDIR=${MOSMLHOME}/lib/moscow_ml
-# TOOLDIR=${MOSMLHOME}/libexec/moscow_ml
+BINDIR=${DESTDIR}${PREFIX}/bin
+LIBDIR=${DESTDIR}${PREFIX}/lib/mosml
+INCDIR=${DESTDIR}${PREFIX}/include/mosml
+DOCDIR=${DESTDIR}${DOCSDIR}
+TOOLDIR=${DESTDIR}${PREFIX}/libexec/mosml
 
 CAMLRT=../runtime
 
@@ -142,7 +140,7 @@ MOSMLDEP=../camlrunm ../mosmldep
 # For cross-compiling to Win 32 (from Linux) (development only)
 # CPP=/lib/cpp -P -traditional -Umsdos -Uunix -Dwin32
 
-CC=gcc
+CC ?= gcc
 
 .SUFFIXES :
 .SUFFIXES : .sml .sig .ui .uo .mlp .lex .c .o
