--- cnf/mak/afnix-rule.mak.orig	Fri Apr 20 08:10:38 2007
+++ cnf/mak/afnix-rule.mak	Sat May 26 23:59:55 2007
@@ -24,7 +24,7 @@
 ifeq ($(CCMODE),optimized)
   ENVFLAGS      = $(STDEVFLAGS) $(PLTEVFLAGS)
   CPPFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CPPCCFLAGS) $(OPTCCFLAGS)
-  CXXFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
+  CXXFLAGS     += $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
   CCDEFINE      = $(STDDEFINES) $(PLTDEFINES) $(OPTDEFINES)
 endif
 
@@ -95,7 +95,7 @@
 -include *.d
 
 %.o   : %.cpp 
-	$(ENVFLAGS) $(CC) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
+	$(ENVFLAGS) $(CC) $(CXXFLAGS) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
 
 %.o   : %.cxx 
 	$(ENVFLAGS) $(CC) $(XXFLAGS) $(DEFINES) $(XXINCLS) -o $@ -c $<
@@ -124,7 +124,7 @@
 
 install-arlib: $(ARLIB)
 	@$(MKDIR) $(LIBDIR)
-	@$(CP)    $(ARLIB) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM)    $(ARLIB) $(LIBDIR)
 .PHONY: install-arlib
 else
 install-arlib: $(ARLIB)
@@ -148,7 +148,7 @@
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)       $(LIBDIR)
-	@$(CP) $(DYLIB) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(DYLIB) $(LIBDIR)
 .PHONY: install-dylib
 endif
 
@@ -167,11 +167,8 @@
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)        $(LIBDIR)
-	@$(CP) $(SOVRS)  $(LIBDIR)
-	@$(RM) $(LIBDIR)/$(SOMIN)
-	@$(RM) $(LIBDIR)/$(DYLIB)
-	@$(LN) $(SOVRS)  $(LIBDIR)/$(SOMIN)
-	@$(LN) $(SOMIN)  $(LIBDIR)/$(DYLIB)
+	@$(BSD_INSTALL_PROGRAM) $(SOVRS)  $(LIBDIR)/$(SOMAJ)
+	@$(LN) $(SOMAJ)  $(LIBDIR)/$(DYLIB)
 .PHONY: install-dylib
 endif
 
@@ -194,7 +191,7 @@
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)        $(LIBDIR)
-	@$(CP) $(DYVRS)  $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(DYVRS)  $(LIBDIR)
 	@$(RM) $(LIBDIR)/$(DYLIB)
 	@$(RM) $(LIBDIR)/$(DYMAJ)
 	@$(RM) $(LIBDIR)/$(DYMIN)
