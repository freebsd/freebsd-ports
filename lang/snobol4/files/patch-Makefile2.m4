--- Makefile2.m4.orig	2020-06-22 02:02:06 UTC
+++ Makefile2.m4
@@ -615,8 +615,8 @@ snopea.1: snopea snolib/snopea.sno snobol4
 snopea.1.html: snopea snolib/snopea.sno snobol4
 	$(SNOPEA) snopea snopea.1.html
 
-docs $(GENERATED_DOCS_DOCDIR): snopea snolib/snopea.sno snobol4 always
-	cd doc; make
+docs $(GENERATED_DOCS_DOCDIR): snopea snolib/snopea.sno xsnobol4 always
+	cd doc; ${MAKE}
 
 always:
 
@@ -631,17 +631,18 @@ INSTALL_H=[include]/h.h [include]/snotypes.h [include]
 # generated SNOLIB files (host.sno generated at top level)
 GENSNOLIB=host.sno config.sno
 
-SNOLIB_FILES=snolib/*.sno $(GENSNOLIB) $(MODULES_INCLUDE)
+SNOLIB_FILES=snolib/*.sno $(GENSNOLIB)
 
-install: snobol4 sdb timing.out $(GENERATED_DOCS)
+install: xsnobol4 sdb $(GENERATED_DOCS)
+	cp xsnobol4$(EXT) snobol4$(EXT)
 	$(INSTALL) -d $(BINDIR)
 	$(INSTALL) $(INSTALL_BIN_FLAGS) snobol4 $(BINDIR)/snobol4-$(VERS)
 	$(INSTALL) sdb $(BINDIR)/sdb-$(VERS)
 	$(INSTALL) snopea $(BINDIR)/snopea-$(VERS)
 	rm -f $(BINDIR)/snobol4 $(BINDIR)/sdb $(BINDIR)/snopea
-	ln -s $(BINDIR)/snobol4-$(VERS) $(BINDIR)/snobol4
-	ln -s $(BINDIR)/sdb-$(VERS) $(BINDIR)/sdb
-	ln -s $(BINDIR)/snopea-$(VERS) $(BINDIR)/snopea
+	cd $(BINDIR) && ln -s snobol4-$(VERS) snobol4
+	cd $(BINDIR) && ln -s sdb-$(VERS) sdb
+	cd $(BINDIR) && ln -s snopea-$(VERS) snopea
 	$(INSTALL) -d $(MAN1DIR)
 	for F in $(GENERATED_DOCS_DOCDIR1); do \
 		$(INSTALL) -m 644 $$F $(MAN1DIR); \
@@ -668,15 +669,12 @@ install: snobol4 sdb timing.out $(GENERATED_DOCS)
 	for F in $(SNOLIB_FILES); do \
 		$(INSTALL) -m 644 $$F $(SNOLIB_LIB); \
 	done
-	for M in $(MODULES); do \
-		(cd modules/$$M; $(RUNSETUP) install); \
-	done
 	$(INSTALL) -d $(INCLUDE_DIR)
 	for F in $(INSTALL_H); do \
 		$(INSTALL) -m 644 $$F $(INCLUDE_DIR); \
 	done
 	$(INSTALL) -d $(DOC_DIR)
-	for F in doc/load.txt doc/*.html modules/*/*.html; do \
+	for F in doc/load.txt doc/*.html; do \
 		$(INSTALL) -m 644 $$F $(DOC_DIR); \
 	done
 ifdef([INSTALL_SYSDEP],[	]INSTALL_SYSDEP
