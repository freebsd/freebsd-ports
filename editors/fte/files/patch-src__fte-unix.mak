--- src/fte-unix.mak.orig	2010-03-16 18:03:51 UTC
+++ src/fte-unix.mak
@@ -5,10 +5,10 @@
 
 #  vfte - for Linux console directly (with limitations, see con_linux.cpp)
 
-TGT_NFTE = nfte
+#TGT_NFTE = nfte
 #TGT_QFTE = qfte
-TGT_SFTE = sfte
-TGT_VFTE = vfte
+#TGT_SFTE = sfte
+#TGT_VFTE = vfte
 TGT_XFTE = xfte
 
 TARGETS = $(TGT_XFTE) $(TGT_VFTE) $(TGT_NFTE) $(TGT_SFTE) $(TGT_QFTE)
@@ -27,15 +27,16 @@ LD = $(CXX)
 CPPOPTIONS = -Wall -Wpointer-arith -Wconversion -Wwrite-strings -Winline
 
 # try this for smaller/faster code and less dependencies
-#NOEXCEPTION = -fno-rtti -fno-exceptions
+NOEXCEPTION = -fno-rtti -fno-exceptions
 
 
 # choose your os here
 
 #######################################################################
 # Linux
-UOS      = -DLINUX
-#XLIBDIR  = 
+UOS      = -DFREEBSD
+XINCDIR  = -I$(LOCALBASE)/include
+XLIBDIR  = -L$(LOCALBASE)/lib
 
 #######################################################################
 # HP/UX
@@ -55,7 +56,7 @@ UOS      = -DLINUX
 #MINCDIR  = -I/usr/include/Motif1.2
 #MLIBDIR  = -L/usr/lib/Motif1.2
 
-SINCDIR   = -I/usr/include/slang
+#SINCDIR   = -I/usr/include/slang
 
 #######################################################################
 # AIX
@@ -111,18 +112,18 @@ SINCDIR   = -I/usr/include/slang
 
 #######################################################################
 
-QTDIR   = /usr/lib64/qt-3.3
+#QTDIR   = /usr/lib64/qt-3.3
 #/users/markom/qt
-QLIBDIR  = -L$(QTDIR)/lib
+#QLIBDIR  = -L$(QTDIR)/lib
 #QINCDIR  = -I$(QTDIR)/include
 #QINCDIR  = -I/usr/include/qt
-QINCDIR =  -I/usr/include/qt3 -I/usr/lib64/qt-3.3/include
-MOC      = moc
+#QINCDIR =  -I/usr/include/qt3 -I/usr/lib64/qt-3.3/include
+#MOC      = moc
 
 LIBDIRS   =
 INCDIRS   = $(XINCDIR) $(QINCDIR) $(MINCDIR) $(SINCDIR)
 
-OPTIMIZE = -g # -O -g
+#OPTIMIZE = -g # -O -g
 #OPTIMIZE = -O2
 #OPTIMIZE = -Os
 #OPTIMIZE = -O2 -s
@@ -148,7 +149,7 @@ SRCS = $(OBJS:.o=.cpp)\
  $(XOBJS:.o=.cpp)
 
 XLIBS    = $(XLIBDIR) -lX11 $(SOCKETLIB) $(XPMLIB) $(XTLIB)
-VLIBS    = $(VLIBDIR) -lgpm
+VLIBS    = $(VLIBDIR) -lncurses
 NLIBS    = $(NLIBDIR) -lncurses
 SLIBS    = $(SLIBDIR) -lslang
 #QLIBS    = $(QLIBDIR) -lqt
@@ -223,6 +224,6 @@ clean:
 #
 # include dependency files if they exist
 #
-ifneq ($(wildcard .depend),)
-include .depend
-endif
+#ifneq ($(wildcard .depend),)
+#include .depend
+#endif
