--- Makefile.inc.orig	2003-03-04 20:14:28 UTC
+++ Makefile.inc
@@ -26,8 +26,8 @@
 DEBUG=-g $(PDEBUG)
 OPT=
 
-REXX_INCLUDE=$(HOME)/regina
-CFLAGS=$(DEBUG) $(OPT) $(PCFLAGS) $(PCDEFS) -I $(REXX_INCLUDE)
+REXX_INCLUDE=/usr/local/include
+CFLAGS+=$(DEBUG) $(OPT) $(PCFLAGS) $(PCDEFS) -I $(REXX_INCLUDE)
 LDFLAGS=$(PLDFLAGS)
 LIBS=$(PLIBS)
 LIBFILE=librexxutil
