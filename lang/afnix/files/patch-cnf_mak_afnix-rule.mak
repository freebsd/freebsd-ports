--- cnf/mak/afnix-rule.mak.orig	Thu Aug 25 07:13:37 2005
+++ cnf/mak/afnix-rule.mak	Wed Aug 31 22:43:14 2005
@@ -22,7 +22,7 @@
 
 ifeq ($(CCMODE),optimized)
   CPPFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CPPCCFLAGS) $(OPTCCFLAGS)
-  CXXFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
+  CXXFLAGS      += $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
   CCDEFINE      = $(STDDEFINES) $(PLTDEFINES) $(OPTDEFINES)
 endif
 
@@ -78,7 +78,7 @@
 -include *.d
 
 %.o   : %.cpp 
-	$(CC) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
+	$(CC) $(CXXFLAGS) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
 
 %.o   : %.cxx 
 	$(CC) $(XXFLAGS) $(DEFINES) $(XXINCLS) -o $@ -c $<
@@ -95,7 +95,7 @@
 
 install-arlib: $(ARLIB)
 	@$(MKDIR) $(LIBDIR)
-	@$(CP)    $(ARLIB) $(LIBDIR)
+	@$(BSD_INSTALL_DATA)    $(ARLIB) $(LIBDIR)
 .PHONY: install-arlib
 else
 install-arlib: $(ARLIB)
@@ -117,7 +117,7 @@
 
 install-solib : $(SOLIB)
 	@$(MKDIR)       $(LIBDIR)
-	@$(CP) $(SOLIB) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(SOLIB) $(LIBDIR)
 .PHONY: install-solib
 endif
 
@@ -136,7 +136,7 @@
 
 install-solib : $(SOVERS)
 	@$(MKDIR)        $(LIBDIR)
-	@$(CP) $(SOVERS) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(SOVERS) $(LIBDIR)
 	@$(RM) $(LIBDIR)/$(SONAME)
 	@$(RM) $(LIBDIR)/$(SOLIB)
 	@$(LN) $(SOVERS) $(LIBDIR)/$(SONAME)
