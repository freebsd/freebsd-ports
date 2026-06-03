--- common.mk.orig	2025-11-17 12:39:04 UTC
+++ common.mk
@@ -427,14 +427,14 @@ do-install-all: pre-install-all $(DOT_WAIT) docs
 install-all: pre-install-all do-install-all post-install-all
 pre-install-all:: all pre-install-local pre-install-ext pre-install-gem pre-install-doc
 do-install-all: pre-install-all $(DOT_WAIT) docs
-	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=$(INSTALL_ALL) $(INSTALL_DOC_OPTS)
+	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=$(INSTALL_ALL) --exclude=gem $(INSTALL_DOC_OPTS)
 post-install-all:: post-install-local post-install-ext post-install-gem post-install-doc
 	@$(NULLCMD)
 
 install-nodoc: pre-install-nodoc do-install-nodoc post-install-nodoc
 pre-install-nodoc:: pre-install-local pre-install-ext pre-install-gem
 do-install-nodoc: main pre-install-nodoc
-	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=$(INSTALL_ALL) --exclude=doc
+	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=$(INSTALL_ALL) --exclude=doc --exclude=gem
 post-install-nodoc:: post-install-local post-install-ext post-install-gem
 
 install-local: pre-install-local do-install-local post-install-local
