--- hotspot/make/bsd/makefiles/vm.make.orig	2016-12-30 04:31:06 UTC
+++ hotspot/make/bsd/makefiles/vm.make
@@ -119,6 +119,9 @@ LFLAGS += $(EXTRA_CFLAGS)
 # Darwin is non-executable-stack by default
 ifneq ($(OS_VENDOR), Darwin)
 LFLAGS += -Xlinker -z -Xlinker noexecstack
+ifeq ($(Platform_arch_model), x86_32)
+LFLAGS += -Xlinker -z -Xlinker notext
+endif
 endif
 
 LIBS += -lm -pthread
