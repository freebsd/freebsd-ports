--- deps/llvm.mk.orig	2024-04-30 17:45:14 UTC
+++ deps/llvm.mk
@@ -214,7 +214,7 @@ $$(SRCCACHE)/$$(LLVM_SRC_DIR)/$1.patch-applied: $$(SRC
 LLVM_PATCH_PREV :=
 define LLVM_PATCH
 $$(SRCCACHE)/$$(LLVM_SRC_DIR)/$1.patch-applied: $$(SRCCACHE)/$$(LLVM_SRC_DIR)/source-extracted | $$(SRCDIR)/patches/$1.patch $$(LLVM_PATCH_PREV)
-	cd $$(SRCCACHE)/$$(LLVM_SRC_DIR)/llvm && patch -p1 -f < $$(SRCDIR)/patches/$1.patch
+	cd $$(SRCCACHE)/$$(LLVM_SRC_DIR)/$2 && patch -p$3 -f < $$(SRCDIR)/patches/$1.patch
 	echo 1 > $$@
 # declare that applying any patch must re-run the compile step
 $$(LLVM_BUILDDIR_withtype)/build-compiled: $$(SRCCACHE)/$$(LLVM_SRC_DIR)/$1.patch-applied
@@ -230,7 +230,8 @@ endef
 LLVM_PATCH_PREV := $$(SRCCACHE)/$$(LLVM_SRC_DIR)/$1.patch-applied
 endef
 
-$(eval $(call LLVM_PATCH,llvm-ittapi-cmake))
+$(eval $(call LLVM_PATCH,llvm-ittapi-cmake,llvm,1))
+$(eval $(call LLVM_PATCH,llvm-version-fixes,.,0))
 
 ifeq ($(USE_SYSTEM_ZLIB), 0)
 $(LLVM_BUILDDIR_withtype)/build-configured: | $(build_prefix)/manifest/zlib
