--- deps/llvm.mk.orig	2022-05-18 05:08:54 UTC
+++ deps/llvm.mk
@@ -277,7 +277,7 @@ $(eval $(call LLVM_PATCH,llvm7-symver-jlprefix))
 endif
 
 # declare that all patches must be applied before running ./configure
-$(LLVM_BUILDDIR_withtype)/build-configured: | $(LLVM_PATCH_PREV) $(build_prefix)/manifest/zlib
+$(LLVM_BUILDDIR_withtype)/build-configured: | $(LLVM_PATCH_PREV)
 
 $(LLVM_BUILDDIR_withtype)/build-configured: $(SRCCACHE)/$(LLVM_SRC_DIR)/source-extracted | $(llvm_python_workaround)
 	mkdir -p $(dir $@)
