--- src/common_rules.mak.orig	Thu May 31 20:43:14 2001
+++ src/common_rules.mak	Fri Oct  5 00:29:33 2001
@@ -86,8 +86,8 @@
 	ln -s $(STLDEBUG_DYNLIB) $(OUTDIR)/$(STLDEBUG_NAME).$(DYNEXT)
 
 install_unix :
-	-$(RM) $(INSTALLDIR_INC)
-	for dir in $(HEADER_DIRS1); \
+	@-$(RM) $(INSTALLDIR_INC)
+	@for dir in $(HEADER_DIRS1); \
 	do \
 	  ./mkinstalldirs $(INSTALLDIR_INC)/$$dir; \
 	  for file in `cat ../stlport/$$dir/export`; \
@@ -95,7 +95,7 @@
 		$(INSTALL_H) ../stlport/$$dir/$$file $(INSTALLDIR_INC)/$$dir ; \
           done \
 	done
-	for dir in $(HEADER_DIRS2); \
+	@for dir in $(HEADER_DIRS2); \
 	do \
 	  ./mkinstalldirs $(INSTALLDIR_INC)/$$dir; \
 	  for file in `ls ../stlport/$$dir/*.*`; \
@@ -103,16 +103,16 @@
 		$(INSTALL_H) $$file $(INSTALLDIR_INC)/$$dir ; \
           done \
 	done
-	./mkinstalldirs $(INSTALLDIR_LIB)
-	for file in `ls $(OUTDIR)/$(LIB_BASENAME)*`; \
+	@./mkinstalldirs $(INSTALLDIR_LIB)
+	@for file in `ls $(OUTDIR)/$(LIB_BASENAME)*`; \
 	do \
          $(RM)  $(INSTALLDIR_LIB)/$$file; \
 	 $(INSTALL_LIB)  $$file $(INSTALLDIR_LIB); \
 	done
-	$(RM) $(INSTALLDIR_LIB)/$(RELEASE_NAME).$(DYNEXT)
-	$(RM) $(INSTALLDIR_LIB)/$(STLDEBUG_NAME).$(DYNEXT)
-	ln -s $(INSTALLDIR_LIB)/$(RELEASE_DYNLIB) $(INSTALLDIR_LIB)/$(RELEASE_NAME).$(DYNEXT)
-	ln -s $(INSTALLDIR_LIB)/$(STLDEBUG_DYNLIB) $(INSTALLDIR_LIB)/$(STLDEBUG_NAME).$(DYNEXT)
+	@$(RM) $(INSTALLDIR_LIB)/$(RELEASE_NAME).$(DYNEXT)
+	@$(RM) $(INSTALLDIR_LIB)/$(STLDEBUG_NAME).$(DYNEXT)
+	@ln -s $(INSTALLDIR_LIB)/$(RELEASE_DYNLIB) $(INSTALLDIR_LIB)/$(RELEASE_NAME).$(DYNEXT)
+	@ln -s $(INSTALLDIR_LIB)/$(STLDEBUG_DYNLIB) $(INSTALLDIR_LIB)/$(STLDEBUG_NAME).$(DYNEXT)
 
 $(OUTDIR)$(PATH_SEP)$(RELEASE_DYNLIB) : $(OUTDIR) $(RELEASE_OBJDIR_dynamic) $(DEF_FILE) $(RELEASE_OBJECTS_dynamic)
 	$(DYN_LINK) $(DYNLINK_OUT)$(OUTDIR)$(PATH_SEP)$(RELEASE_DYNLIB) $(LDFLAGS_RELEASE_dynamic) $(RELEASE_OBJECTS_dynamic) $(LDLIBS_RELEASE_dynamic) 
