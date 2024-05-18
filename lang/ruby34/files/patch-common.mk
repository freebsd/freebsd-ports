--- common.mk.orig	2024-12-12 01:10:13 UTC
+++ common.mk
@@ -487,17 +487,17 @@ install-all: pre-install-all do-install-all post-insta
 $(ruby_pc): $(srcdir)/template/ruby.pc.in config.status
 
 install-all: pre-install-all do-install-all post-install-all
-pre-install-all:: all pre-install-local pre-install-ext pre-install-gem pre-install-doc
+pre-install-all:: all pre-install-local pre-install-ext pre-install-doc
 do-install-all: pre-install-all $(DOT_WAIT) docs
-	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=all $(INSTALL_DOC_OPTS)
-post-install-all:: post-install-local post-install-ext post-install-gem post-install-doc
+	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=all --exclude=gem $(INSTALL_DOC_OPTS)
+post-install-all:: post-install-local post-install-ext post-install-doc
 	@$(NULLCMD)
 
 install-nodoc: pre-install-nodoc do-install-nodoc post-install-nodoc
-pre-install-nodoc:: pre-install-local pre-install-ext pre-install-gem
+pre-install-nodoc:: pre-install-local pre-install-ext
 do-install-nodoc: main pre-install-nodoc
-	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=all --exclude=doc
-post-install-nodoc:: post-install-local post-install-ext post-install-gem
+	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=all --exclude=doc --exclude=gem
+post-install-nodoc:: post-install-local post-install-ext
 
 install-local: pre-install-local do-install-local post-install-local
 pre-install-local:: pre-install-bin pre-install-lib pre-install-man
