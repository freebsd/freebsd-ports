--- binaries/make.inc.orig	Fri Sep 28 21:36:07 2007
+++ binaries/make.inc	Fri Sep 28 21:37:31 2007
@@ -1,5 +1,6 @@
-CFLAGS+=-DNDEBUG -DLINUX -O2 -fno-strict-aliasing -Wall -ffloat-store -pipe -g -MF .depends/$*.d -MMD
+CFLAGS+=-I$(LOCALBASE)/include -DNDEBUG -DLINUX -DDATADIR='"$(Q2DIR)"' -DLIBDIR='"$(LIBDIR)"' -O2 -fno-strict-aliasing -Wall -pipe -g -MF .depends/$*.d -MMD
 ALLOBJ:=$(ALLSRC:.c=.o)
+LDFLAGS+=-L$(LOCALBASE)/lib
 
 .PHONY: clean distclean
 
