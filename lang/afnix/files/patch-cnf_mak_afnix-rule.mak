--- cnf/mak/afnix-rule.mak.orig	Wed Jan 12 06:05:00 2005
+++ cnf/mak/afnix-rule.mak	Wed Feb 16 19:18:04 2005
@@ -62,8 +62,8 @@
 endif
 
 ifeq ($(LKMODE),soname)
-SONAME		= $(SOLIB).$(MAJOR).$(MINOR)
-SOVERS		= $(SOLIB).$(MAJOR).$(MINOR).$(PATCH)
+SONAME		= $(SOLIB).$(MAJOR)
+SOVERS		= $(SOLIB).$(MAJOR)
 endif
 
 # ----------------------------------------------------------------------------
@@ -124,17 +124,13 @@
 $(SOLIB) : $(SOVERS)
 	@$(MKDIR)        $(BLDLIB)
 	@$(CP) $(SOVERS) $(BLDLIB)
-	@$(RM) $(BLDLIB)/$(SOLIB)
 	@$(RM) $(BLDLIB)/$(SONAME)
-	@$(LN) $(SOVERS) $(BLDLIB)/$(SONAME)
 	@$(LN) $(SONAME) $(BLDLIB)/$(SOLIB)
 
 install-solib : $(SOVERS)
 	@$(MKDIR)        $(LIBDIR)
 	@$(CP) $(SOVERS) $(LIBDIR)
-	@$(RM) $(LIBDIR)/$(SONAME)
 	@$(RM) $(LIBDIR)/$(SOLIB)
-	@$(LN) $(SOVERS) $(LIBDIR)/$(SONAME)
 	@$(LN) $(SONAME) $(LIBDIR)/$(SOLIB)
 .PHONY: install-solib
 endif
