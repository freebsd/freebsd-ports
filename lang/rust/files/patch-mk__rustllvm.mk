--- ./mk/rustllvm.mk.orig	2012-01-21 05:09:09.000000000 +0800
+++ ./mk/rustllvm.mk	2012-01-26 10:41:49.661804374 +0800
@@ -37,7 +37,7 @@
 
 rustllvm/$(1)/%.o: rustllvm/%.cpp $$(MKFILE_DEPS) $$(LLVM_CONFIG_$(1))
 	@$$(call E, compile: $$@)
-	$$(Q)$$(call CFG_COMPILE_C_$(1), $$@, $$(LLVM_CXXFLAGS_$(1)) $$(RUSTLLVM_INCS_$(1))) $$<
+	$$(Q)$$(call CFG_COMPILE_C_$(1), $$@, $$(subst -I, -iquote , $$(LLVM_CXXFLAGS_$(1))) $$(RUSTLLVM_INCS_$(1))) $$<
 endef
 
 # Instantiate template for all stages
