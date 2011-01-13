--- cnf/mak/afnix-rule.mak.orig	2011-01-13 11:16:23.000000000 +0100
+++ cnf/mak/afnix-rule.mak	2011-01-13 18:26:39.000000000 +0100
@@ -24,7 +24,7 @@ endif
 ifeq ($(CCMODE),optimized)
   ENVFLAGS      = $(STDEVFLAGS) $(PLTEVFLAGS)
   CPPFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CPPCCFLAGS) $(OPTCCFLAGS)
-  CXXFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
+  CXXFLAGS     += $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
   CCDEFINE      = $(STDDEFINES) $(PLTDEFINES) $(OPTDEFINES)
 endif
 
@@ -69,7 +69,7 @@ endif
 
 ifeq ($(LKMODE),soname)
 SOMAJ		= $(DYLIB).$(MAJOR)
-SOMIN		= $(DYLIB).$(MAJOR).$(MINOR)
+SOMIN		= $(DYLIB).$(MAJOR)
 SOVRS		= $(DYLIB).$(MAJOR).$(MINOR).$(PATCH)
 endif
 
@@ -95,7 +95,7 @@ else
 -include *.d
 
 %.o   : %.cpp 
-	$(ENVFLAGS) $(CC) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
+	$(ENVFLAGS) $(CC) $(CXXFLAGS) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
 
 %.o   : %.cxx 
 	$(ENVFLAGS) $(CC) $(XXFLAGS) $(DEFINES) $(XXINCLS) -o $@ -c $<
@@ -124,7 +124,7 @@ endif
 
 install-arlib: $(ARLIB)
 	@$(MKDIR) $(LIBDIR)
-	@$(CP)    $(ARLIB) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM)    $(ARLIB) $(LIBDIR)
 .PHONY: install-arlib
 else
 install-arlib: $(ARLIB)
@@ -148,7 +148,7 @@ $(DYLIB) : $(OBJECTS)
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)       $(LIBDIR)
-	@$(CP) $(DYLIB) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(DYLIB) $(LIBDIR)
 .PHONY: install-dylib
 endif
 
@@ -167,11 +167,8 @@ $(DYLIB) : $(SOVRS)
 
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
 
@@ -194,7 +191,7 @@ $(DYLIB) : $(DYVRS)
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)        $(LIBDIR)
-	@$(CP) $(DYVRS)  $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(DYVRS)  $(LIBDIR)
 	@$(RM) $(LIBDIR)/$(DYLIB)
 	@$(RM) $(LIBDIR)/$(DYMAJ)
 	@$(RM) $(LIBDIR)/$(DYMIN)
