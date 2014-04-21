--- hotspot/make/bsd/makefiles/gcc.make
+++ hotspot/make/bsd/makefiles/gcc.make
@@ -216,8 +216,11 @@
 endif
 
 # Flags for generating make dependency flags.
+ifeq (,$(findstring clang,$(shell $(CC) -v 2>&1)))
+DEPFLAGS = -fpch-deps
+endif
 ifneq ("${CC_VER_MAJOR}", "2")
-DEPFLAGS = -fpch-deps -MMD -MP -MF $(DEP_DIR)/$(@:%=%.d)
+DEPFLAGS += -MMD -MP -MF $(DEP_DIR)/$(@:%=%.d)
 endif
 
 # -DDONT_USE_PRECOMPILED_HEADER will exclude all includes in precompiled.hpp.
