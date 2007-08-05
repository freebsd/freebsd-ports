$FreeBSD$

--- ../../hotspot/build/bsd/makefiles/jsig.make.orig	Sun Jul 29 23:03:30 2007
+++ ../../hotspot/build/bsd/makefiles/jsig.make	Sun Jul 29 23:03:30 2007
@@ -22,7 +22,7 @@
 # cause problems with interposing. See CR: 6466665
 # LFLAGS_JSIG += $(MAPFLAG:FILENAME=$(LIBJSIG_MAPFILE))
 
-LFLAGS_JSIG += -D_GNU_SOURCE -pthread
+LFLAGS_JSIG += -D_GNU_SOURCE ${PTHREAD_LIBS}
 
 $(LIBJSIG): $(JSIGSRCDIR)/jsig.c $(LIBJSIG_MAPFILE)
 	@echo Making signal interposition lib...
