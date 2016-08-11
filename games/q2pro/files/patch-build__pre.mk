--- build/pre.mk.orig	Sun Feb  4 16:13:21 2007
+++ build/pre.mk	Sun Feb  4 16:27:54 2007
@@ -25,7 +25,7 @@ CFLAGS+=-g 
 LDFLAGS+=-g
 else
 #CFLAGS += -march=i686 -msse2 -mfpmath=sse -O2 -fno-strict-aliasing -DNDEBUG
-CFLAGS+=-ffloat-store -O2 -fno-strict-aliasing -DNDEBUG
+CFLAGS+= -DNDEBUG
 LDFLAGS+=-s
 endif
 
@@ -48,10 +48,10 @@ SRCFILES_WIN32=#blank
 ASMFILES_WIN32=#blank
 VPATH_WIN32=$(RCDIR)
 
-DATADIR?=/usr/share/games/quake2
-LIBDIR?=/usr/lib/games/quake2
-CFLAGS_LINUX=-DDATADIR='"$(DATADIR)"' -DLIBDIR='"$(LIBDIR)"'
-LDFLAGS_LINUX=#blank
+DATADIR?=$(Q2DIR)
+LIBDIR?=$(PREFIX)/lib/q2pro
+CFLAGS_LINUX=-I$(LOCALBASE)/include -DDATADIR='"$(DATADIR)"' -DLIBDIR='"$(LIBDIR)"'
+LDFLAGS_LINUX=-L$(LOCALBASE)/lib
 SRCFILES_LINUX=#blank
 ASMFILES_LINUX=#blank
 
