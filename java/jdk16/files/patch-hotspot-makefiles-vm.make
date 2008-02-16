$FreeBSD$

--- ../../hotspot/build/bsd/makefiles/vm.make.orig	Sat Feb 16 10:44:36 2008
+++ ../../hotspot/build/bsd/makefiles/vm.make	Sat Feb 16 10:45:02 2008
@@ -70,7 +70,7 @@
 LIBS += -lm
 
 ifneq (Darwin, $(UNAME.s))
-LIBS += -pthread
+LIBS += ${PTHREAD_LIBS}
 endif
 
 # By default, link the *.o into the library, not the executable.
