--- hotspot/make/bsd/makefiles/vm.make.orig
+++ hotspot/make/bsd/makefiles/vm.make
@@ -132,6 +132,10 @@ LIBS += -lm
 
 ifeq ($(USE_CLANG),)
   LIBS += -pthread
+else
+  ifneq ($(OS_VENDOR), Darwin)
+    LIBS += -pthread
+  endif
 endif
 
 # By default, link the *.o into the library, not the executable.
