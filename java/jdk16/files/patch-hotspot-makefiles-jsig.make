$FreeBSD$

--- ../../hotspot/build/bsd/makefiles/jsig.make.orig	Sat Feb 16 09:16:41 2008
+++ ../../hotspot/build/bsd/makefiles/jsig.make	Sat Feb 16 09:17:01 2008
@@ -30,7 +30,7 @@
 LFLAGS_JSIG += -D_GNU_SOURCE
 
 ifneq (Darwin, $(UNAME.s))
-  LFLAGS_JSIG += -pthread
+  LFLAGS_JSIG += ${PTHREAD_LIBS}
 endif
 
 $(LIBJSIG): $(JSIGSRCDIR)/jsig.c $(LIBJSIG_MAPFILE)
