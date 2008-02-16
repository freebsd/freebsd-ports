$FreeBSD$

--- ../../hotspot/build/bsd/makefiles/gcc.make.orig	Tue Feb 12 22:24:15 2008
+++ ../../hotspot/build/bsd/makefiles/gcc.make	Tue Feb 12 22:24:28 2008
@@ -46,7 +46,7 @@
 CFLAGS += -fno-exceptions
 
 ifneq (Darwin, $(UNAME.s))
-CFLAGS += -pthread
+CFLAGS += ${PTHREAD_LIBS}
 endif
 
 CFLAGS += -fcheck-new
