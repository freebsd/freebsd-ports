--- Makefile.inc.orig	Thu Jun 29 02:28:14 2000
+++ Makefile.inc	Wed Apr 10 00:06:57 2002
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
