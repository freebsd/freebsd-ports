--- build/main.mk.orig	2008-07-21 14:43:22.000000000 +0200
+++ build/main.mk	2008-07-21 14:43:48.000000000 +0200
@@ -371,13 +371,13 @@
 	@echo "  Data files..."
 	@mkdir -p $(INSTALL_SHARE_DIR)
 	@cp -rf $(RESOURCES_PATH) $(INSTALL_SHARE_DIR)/
-	@echo "  Documentation..."
-	@mkdir -p $(INSTALL_DOC_DIR)
-	@cp -f README GPL AUTHORS $(INSTALL_DOC_DIR)
-	@cp -f $(addprefix doc/,$(INSTALL_DOCS)) $(INSTALL_DOC_DIR)
-	@mkdir -p $(INSTALL_DOC_DIR)/manual
-	@cp -f $(addprefix doc/manual/,*.html *.css *.png) \
-		$(INSTALL_DOC_DIR)/manual
+	@echo "  Skipping Documentation..."
+#	@mkdir -p $(INSTALL_DOC_DIR)
+#	@cp -f README GPL AUTHORS $(INSTALL_DOC_DIR)
+#	@cp -f $(addprefix doc/,$(INSTALL_DOCS)) $(INSTALL_DOC_DIR)
+#	@mkdir -p $(INSTALL_DOC_DIR)/manual
+#	@cp -f $(addprefix doc/manual/,*.html *.css *.png) \
+#		$(INSTALL_DOC_DIR)/manual
 ifeq ($(CATAPULT_PREBUILT),false)
 ifneq ($(CATAPULT_NO_DESKTOP_HOOKS),true)
 	@echo "  Desktop hooks..."
