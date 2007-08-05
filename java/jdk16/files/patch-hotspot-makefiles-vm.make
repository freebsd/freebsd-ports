$FreeBSD$

--- ../../hotspot/build/bsd/makefiles/vm.make.orig	Sun Jul 29 23:03:30 2007
+++ ../../hotspot/build/bsd/makefiles/vm.make	Sun Jul 29 23:03:30 2007
@@ -67,7 +67,7 @@
 # Extra flags from gnumake's invocation or environment
 CFLAGS += $(EXTRA_CFLAGS)
 
-LIBS += -lm -pthread
+LIBS += -lm ${PTHREAD_LIBS}
 
 # By default, link the *.o into the library, not the executable.
 LINK_INTO$(LINK_INTO) = LIBJVM
