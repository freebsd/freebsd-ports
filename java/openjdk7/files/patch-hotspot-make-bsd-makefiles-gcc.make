--- hotspot/make/bsd/makefiles/gcc.make
+++ hotspot/make/bsd/makefiles/gcc.make
@@ -214,7 +214,11 @@
 
 # Flags for generating make dependency flags.
 ifneq ("${CC_VER_MAJOR}", "2")
-DEPFLAGS = -fpch-deps -MMD -MP -MF $(DEP_DIR)/$(@:%=%.d)
+DEPFLAGS =
+ifeq (,$(findstring clang,$(shell $(CC) -v 2>&1)))
+DEPFLAGS += -fpch-deps
+endif
+DEPFLAGS += -MMD -MP -MF $(DEP_DIR)/$(@:%=%.d)
 endif
 
 # -DDONT_USE_PRECOMPILED_HEADER will exclude all includes in precompiled.hpp.
