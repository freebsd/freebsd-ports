$FreeBSD$

--- ../../hotspot/build/bsd/makefiles/gcc.make.orig	Sun Jul 29 23:03:30 2007
+++ ../../hotspot/build/bsd/makefiles/gcc.make	Sun Jul 29 23:03:30 2007
@@ -39,7 +39,7 @@
 CFLAGS += $(VM_PICFLAG)
 CFLAGS += -fno-rtti
 CFLAGS += -fno-exceptions
-CFLAGS += -pthread
+CFLAGS += ${PTHREAD_LIBS}
 CFLAGS += -fcheck-new
 
 ARCHFLAG = $(ARCHFLAG/$(BUILDARCH))
