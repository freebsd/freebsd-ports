--- source/Makefile.mk.orig	2025-10-15 22:39:36 UTC
+++ source/Makefile.mk
@@ -68,7 +68,7 @@ $(LIBKEFIR_SO).$(LIBKEFIR_SO_VERSION): $(KEFIR_LIB_OBJ
 $(LIBKEFIR_SO).$(LIBKEFIR_SO_VERSION): $(KEFIR_LIB_OBJECT_FILES)
 	@mkdir -p $(shell dirname "$@")
 	@echo "Linking $@"
-	@$(CCLD) -shared -o $@ $(KEFIR_LIB_OBJECT_FILES) $(LDFLAGS)
+	@$(CCLD) -shared -Wl,-soname=$(shell basename "$@") -o $@ $(KEFIR_LIB_OBJECT_FILES) $(LDFLAGS)
 ifneq (,$(findstring release,$(PROFILE)))
 	@echo "Stripping $@"
 	@$(STRIP) $@
