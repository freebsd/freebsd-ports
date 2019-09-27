--- machdef.mk.orig	2017-08-05 16:54:37 UTC
+++ machdef.mk
@@ -27,21 +27,21 @@
 #
 # e93 will install its single executable "e93" in $PREFIX/bin
 # and it will place a directory called "e93lib" in $PREFIX/lib
-PREFIX=/usr/local
+PREFIX?=/usr/local
 
 
 # The following lines may need to be altered if the Tcl
 # files are located elsewhere on your system:
-TCL_INCLUDE=-I/usr/include/tcl8.5
+TCL_INCLUDE=-I$(TCL_INCLUDEDIR)
 TCL_LIB=-L/usr/lib/x86_64-linux-gnu
 # uncomment and change if you want to link with specific versions of Tcl
-TCL_VERSION=8.5
+#TCL_VERSION=8.5
 
 
 # The following lines may need to be altered if the X include and library
 # files are located elsewhere on your system:
-X_INCLUDE=-I/usr/X11R6/include
-X_LIB=-L/usr/X11R6/lib
+X_INCLUDE=-I$(LOCALBASE)/include
+X_LIB=-L$(LOCALBASE)/lib
 
 
 # if your system needs some extra libraries, add them here:
@@ -51,9 +51,9 @@ EXTRALIBS=-lm -ldl
 #MACHINESPEC=-DSOLARIS
 
 # set compiler to use
-CC=gcc
+CC?=gcc
 
 
 # set some compiler options
-OPTIONS=-O2 -Wall -x c++ -g -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE
+OPTIONS=-Wall -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE
 #OPTIONS = -Wall -O2 -x c++ -mcpu=21164a -Wa,-m21164a -g
