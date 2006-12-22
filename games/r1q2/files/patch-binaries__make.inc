--- ./binaries/make.inc.orig	Sat Sep 16 16:16:38 2006
+++ ./binaries/make.inc	Sat Dec 16 17:28:37 2006
@@ -1,7 +1,8 @@
 #turol: for some reason -ffast-math causes strange errors
 #and it's not really any faster
-CFLAGS+=-DNDEBUG -DLINUX -O2 -fno-strict-aliasing -Wall -ffloat-store -pipe -g -MF .depends/$*.d -MMD
+CFLAGS+=-I$(LOCALBASE)/include -I$(X11BASE)/include -DNDEBUG -DLINUX -DDATADIR='"$(Q2DIR)"' -DLIBDIR='"$(LIBDIR)"' -O2 -fno-strict-aliasing -Wall -ffloat-store -pipe -g -MF .depends/$*.d -MMD
 ALLOBJ:=$(ALLSRC:.c=.o)
+LDFLAGS+=-L$(LOCALBASE)/lib -L$(X11BASE)/lib
 
 .PHONY: clean distclean
 
