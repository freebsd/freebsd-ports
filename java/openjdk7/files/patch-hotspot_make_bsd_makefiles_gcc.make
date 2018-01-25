--- hotspot/make/bsd/makefiles/gcc.make.orig
+++ hotspot/make/bsd/makefiles/gcc.make
@@ -112,6 +112,7 @@ ifeq ($(JVM_VARIANT_ZEROSHARK), true)
   CFLAGS += $(LIBFFI_CFLAGS)
   CFLAGS += $(LLVM_CFLAGS)
 endif
+CFLAGS += -std=gnu++98
 CFLAGS += $(VM_PICFLAG)
 CFLAGS += -fno-rtti
 CFLAGS += -fno-exceptions
