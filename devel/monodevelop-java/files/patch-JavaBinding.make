--- JavaBinding.make.orig	2008-03-02 14:16:19.000000000 +0100
+++ JavaBinding.make	2008-03-02 14:15:17.000000000 +0100
@@ -119,25 +119,25 @@
 LOCAL_PKGCONFIG=PKG_CONFIG_PATH=../../local-config:$$PKG_CONFIG_PATH
 
 $(ASSEMBLY) $(ASSEMBLY_MDB): $(build_sources) $(build_resources) $(build_datafiles) $(DLL_REFERENCES) $(PROJECT_REFERENCES) $(build_xamlg_list)
-	make pre-all-local-hook prefix=$(prefix)
+	$(MAKE) pre-all-local-hook prefix=$(prefix)
 	mkdir -p $(dir $(ASSEMBLY))
-	make $(CONFIG)_BeforeBuild
+	$(MAKE) $(CONFIG)_BeforeBuild
 	$(LOCAL_PKGCONFIG) $(ASSEMBLY_COMPILER_COMMAND) $(ASSEMBLY_COMPILER_FLAGS) -out:$(ASSEMBLY) -target:$(COMPILE_TARGET) $(build_sources_embed) $(build_resources_embed) $(build_references_ref)
-	make $(CONFIG)_AfterBuild
-	make post-all-local-hook prefix=$(prefix)
+	$(MAKE) $(CONFIG)_AfterBuild
+	$(MAKE) post-all-local-hook prefix=$(prefix)
 
 
 install-local: $(ASSEMBLY) $(ASSEMBLY_MDB) $(JAVABINDING_PC)
-	make pre-install-local-hook prefix=$(prefix)
+	$(MAKE) pre-install-local-hook prefix=$(prefix)
 	mkdir -p $(INSTALL_DIR)
 	cp $(ASSEMBLY) $(ASSEMBLY_MDB) $(INSTALL_DIR)
 	mkdir -p $(DESTDIR)$(prefix)/lib/pkgconfig
 	test -z '$(JAVABINDING_PC)' || cp $(JAVABINDING_PC) $(DESTDIR)$(prefix)/lib/pkgconfig
-	make post-install-local-hook prefix=$(prefix)
+	$(MAKE) post-install-local-hook prefix=$(prefix)
 
 uninstall-local: $(ASSEMBLY) $(ASSEMBLY_MDB) $(JAVABINDING_PC)
-	make pre-uninstall-local-hook prefix=$(prefix)
+	$(MAKE) pre-uninstall-local-hook prefix=$(prefix)
 	rm -f $(INSTALL_DIR)/$(notdir $(ASSEMBLY))
 	test -z '$(ASSEMBLY_MDB)' || rm -f $(INSTALL_DIR)/$(notdir $(ASSEMBLY_MDB))
 	test -z '$(JAVABINDING_PC)' || rm -f $(INSTALL_DIR)/$(notdir $(JAVABINDING_PC))
-	make post-uninstall-local-hook prefix=$(prefix)
+	$(MAKE) post-uninstall-local-hook prefix=$(prefix)
