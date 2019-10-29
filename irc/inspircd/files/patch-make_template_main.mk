--- make/template/main.mk.orig	2019-10-25 10:40:44 UTC
+++ make/template/main.mk
@@ -206,34 +206,34 @@ finishmessage: target
 	@echo "*************************************"
 
 install: target
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(BASE)
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(BINPATH)
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(CONPATH)
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(DATPATH)
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(EXAPATH)/providers
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(EXAPATH)/services
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(EXAPATH)/sql
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(LOGPATH)
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(MANPATH)
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(MODPATH)
-	@-$(INSTALL) -d -g @GID@ -o @UID@ -m $(INSTMODE_DIR) $(SCRPATH)
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_BIN) "$(BUILDPATH)/bin/inspircd" $(BINPATH)
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_BIN) "$(BUILDPATH)/modules/"*.so $(MODPATH)
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_BIN) @CONFIGURE_DIRECTORY@/inspircd $(SCRPATH) 2>/dev/null
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(BASE)
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(BINPATH)
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(CONPATH)
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(DATPATH)
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(EXAPATH)/providers
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(EXAPATH)/services
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(EXAPATH)/sql
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(LOGPATH)
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(MANPATH)
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(MODPATH)
+	@-$(INSTALL) -d -m $(INSTMODE_DIR) $(SCRPATH)
+	-$(INSTALL) -m $(INSTMODE_BIN) "$(BUILDPATH)/bin/inspircd" $(BINPATH)
+	-$(INSTALL) -m $(INSTMODE_BIN) "$(BUILDPATH)/modules/"*.so $(MODPATH)
+	-$(INSTALL) -m $(INSTMODE_BIN) @CONFIGURE_DIRECTORY@/inspircd $(SCRPATH) 2>/dev/null
 ifeq ($(SYSTEM), darwin)
 	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_BIN) @CONFIGURE_DIRECTORY@/org.inspircd.plist $(SCRPATH) 2>/dev/null
 endif
 ifeq ($(SYSTEM), linux)
 	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_TXT) @CONFIGURE_DIRECTORY@/inspircd.service $(SCRPATH) 2>/dev/null
 endif
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_TXT) @CONFIGURE_DIRECTORY@/inspircd.1 $(MANPATH) 2>/dev/null
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_TXT) @CONFIGURE_DIRECTORY@/inspircd-genssl.1 $(MANPATH) 2>/dev/null
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_BIN) tools/genssl $(BINPATH)/inspircd-genssl 2>/dev/null
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_TXT) docs/conf/*.example $(EXAPATH)
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_TXT) docs/conf/providers/*.example $(EXAPATH)/providers
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_TXT) docs/conf/services/*.example $(EXAPATH)/services
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_TXT) docs/sql/*.sql $(EXAPATH)/sql
-	-$(INSTALL) -g @GID@ -o @UID@ -m $(INSTMODE_PRV) *.pem $(CONPATH) 2>/dev/null
+	-$(INSTALL) -m $(INSTMODE_TXT) @CONFIGURE_DIRECTORY@/inspircd.1 $(MANPATH) 2>/dev/null
+	-$(INSTALL) -m $(INSTMODE_TXT) @CONFIGURE_DIRECTORY@/inspircd-genssl.1 $(MANPATH) 2>/dev/null
+	-$(INSTALL) -m $(INSTMODE_BIN) tools/genssl $(BINPATH)/inspircd-genssl 2>/dev/null
+	-$(INSTALL) -m $(INSTMODE_TXT) docs/conf/*.example $(EXAPATH)
+	-$(INSTALL) -m $(INSTMODE_TXT) docs/conf/providers/*.example $(EXAPATH)/providers
+	-$(INSTALL) -m $(INSTMODE_TXT) docs/conf/services/*.example $(EXAPATH)/services
+	-$(INSTALL) -m $(INSTMODE_TXT) docs/sql/*.sql $(EXAPATH)/sql
+	-$(INSTALL) -m $(INSTMODE_PRV) *.pem $(CONPATH) 2>/dev/null
 	@echo ""
 	@echo "*************************************"
 	@echo "*        INSTALL COMPLETE!          *"
