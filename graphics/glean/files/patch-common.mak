--- ../make/common.mak.orig	Wed Nov  6 19:13:23 2002
+++ ../make/common.mak	Thu Sep 25 16:22:58 2003
@@ -39,11 +39,11 @@
 # Locations of common commands:
 ifeq ($(PLATFORM), Unix)
 	AR:=/usr/bin/ar
-	CC:=/usr/bin/g++
+	CC:=${CXX}
 	INSTALL:=/usr/bin/install -c
 	RANLIB:=/usr/bin/ranlib
 	RM:=/bin/rm
-	SED:=/bin/sed
+	SED:=/usr/bin/sed
 	SHELL:=/bin/sh
 	MKDIR:=/bin/mkdir
 endif # Unix
@@ -72,14 +72,14 @@
 ifeq ($(PLATFORM), Unix)
 	# Note:  Do *not* list standard system #include directories here,
 	# because some compilers complain about them.
-	XINC:=-I/usr/include/X11
-	XLIB:=/usr/X11R6/lib
-	GLINC:=#-I/usr/include
-	GLLIB:=/usr/lib
-	GLUTINC:=#-I/usr/include
-	GLUTLIB:=/usr/lib
-	TIFFINC:=#-I/usr/include
-	TIFFLIB:=/usr/lib
+	XINC:=-I${X11BASE}/include
+	XLIB:=${X11BASE}/lib
+	GLINC:=-I${X11BASE}/include
+	GLLIB:=${X11BASE}/lib
+	GLUTINC:=-I${X11BASE}/include
+	GLUTLIB:=${X11BASE}/lib
+	TIFFINC:=-I${LOCALBASE}/include
+	TIFFLIB:=${LOCALBASE}/lib
 	EXTRALIBS:=
 endif # Unix
 ifeq ($(PLATFORM), BeOS)
@@ -166,10 +162,7 @@
 	$(TIFFINC)
 OPT:=		# Optimization options
 ifeq ($(PLATFORM), Unix)
-_OPT=\
-	-march=pentiumpro \
-	-O -fno-unroll-all-loops \
-	$(OPT)
+_OPT= ${CFLAGS}
 endif # Unix
 ifeq ($(PLATFORM), BeOS)
 _OPT=\
@@ -183,7 +176,6 @@
 WARN:=		# warning options
 ifeq ($(PLATFORM), Unix)
 _WARN=\
-	-Wall \
 	-W \
 	$(WARN)
 endif # Unix
