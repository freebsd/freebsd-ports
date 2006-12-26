--- ./build/pre.mk.orig	Mon Dec 25 17:07:02 2006
+++ ./build/pre.mk	Mon Dec 25 17:07:02 2006
@@ -5,29 +5,28 @@
 include ../../detect.mk
 
 ifdef build-prefix
-CC = $(build-prefix)-gcc
+CC ?= $(build-prefix)-gcc
 WINDRES = $(build-prefix)-windres
 else
-CC = gcc
+CC ?= gcc
 WINDRES = windres
 endif
 
 INSTALLDIR = $(CURDIR)/../../..
 OUTPUTDIR = $(CURDIR)/..
 INCLUDEDIR = $(INSTALLDIR)/include
-LIBDIR = #blank
 
 VPATH = $(INSTALLDIR)/asm \
 	$(INSTALLDIR)/shared \
 	$(INSTALLDIR)/source
 
 ifdef debug
-CFLAGS = -g 
-LDFLAGS = -g
+CFLAGS += -g 
+LDFLAGS += -g
 else
-#CFLAGS = -march=i686 -msse2 -mfpmath=sse -O2 -fno-strict-aliasing -DNDEBUG
-CFLAGS = -march=i386 -ffloat-store -O2 -fno-strict-aliasing -DNDEBUG
-LDFLAGS = -s
+#CFLAGS += -march=i686 -msse2 -mfpmath=sse -O2 -fno-strict-aliasing -DNDEBUG
+CFLAGS += -ffloat-store -O2 -fno-strict-aliasing -DNDEBUG
+LDFLAGS += -s
 endif
 
 CFLAGS += -I$(INCLUDEDIR) \
@@ -61,7 +60,7 @@
 SRCFILES_WINCE = #blank
 ASMFILES_WINCE = #blank
 
-CFLAGS_LINUX = #blank
-LDFLAGS_LINUX = #blank
+CFLAGS_LINUX = -I$(LOCALBASE)/include -I$(X11BASE)/include -DDATADIR='"$(Q2DIR)"' -DLIBDIR='"$(LIBDIR)"'
+LDFLAGS_LINUX = -L$(LOCALBASE)/lib -L$(X11BASE)/lib
 SRCFILES_LINUX = #blank
 ASMFILES_LINUX = #blank
