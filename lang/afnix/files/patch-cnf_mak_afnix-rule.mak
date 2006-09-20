--- cnf/mak/afnix-rule.mak.orig	Thu Aug 25 07:13:37 2005
+++ cnf/mak/afnix-rule.mak	Wed Aug 31 22:43:14 2005
@@ -24,7 +24,7 @@
 ifeq ($(CCMODE),optimized)
   ENVFLAGS      = $(STDEVFLAGS) $(PLTEVFLAGS)
   CPPFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CPPCCFLAGS) $(OPTCCFLAGS)
-  CXXFLAGS      = $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
+  CXXFLAGS     += $(STDCCFLAGS) $(PLTCCFLAGS) $(CXXCCFLAGS) $(OPTCCFLAGS)
   CCDEFINE      = $(STDDEFINES) $(PLTDEFINES) $(OPTDEFINES)
 endif
 
@@ -89,7 +89,7 @@
 -include *.d
 
 %.o   : %.cpp 
-	$(ENVFLAGS) $(CC) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
+	$(ENVFLAGS) $(CC) $(CXXFLAGS) $(PPFLAGS) $(DEFINES) $(PPINCLS) -o $@ -c $<
 
 %.o   : %.cxx 
 	$(ENVFLAGS) $(CC) $(XXFLAGS) $(DEFINES) $(XXINCLS) -o $@ -c $<
@@ -117,7 +117,7 @@
 
 install-arlib: $(ARLIB)
 	@$(MKDIR) $(LIBDIR)
-	@$(CP)    $(ARLIB) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM)    $(ARLIB) $(LIBDIR)
 .PHONY: install-arlib
 else
 install-arlib: $(ARLIB)
@@ -141,7 +141,7 @@
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)       $(LIBDIR)
-	@$(CP) $(DYLIB) $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(DYLIB) $(LIBDIR)
 .PHONY: install-dylib
 endif
 
@@ -160,8 +160,5 @@
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)        $(LIBDIR)
-	@$(CP) $(SOVRS)  $(LIBDIR)
-	@$(RM) $(LIBDIR)/$(SOMIN)
-	@$(RM) $(LIBDIR)/$(DYLIB)
-	@$(LN) $(SOVRS)  $(LIBDIR)/$(SOMIN)
-	@$(LN) $(SOMIN)  $(LIBDIR)/$(DYLIB)
+	@$(BSD_INSTALL_PROGRAM) $(SOVRS)  $(LIBDIR)/$(SOMAJ)
+	@$(LN) $(SOMAJ)  $(LIBDIR)/$(DYLIB)
@@ -187,7 +187,7 @@
 
 install-dylib : $(DYLIB)
 	@$(MKDIR)        $(LIBDIR)
-	@$(CP) $(DYVRS)  $(LIBDIR)
+	@$(BSD_INSTALL_PROGRAM) $(DYVRS)  $(LIBDIR)
 	@$(RM) $(LIBDIR)/$(DYLIB)
 	@$(RM) $(LIBDIR)/$(DYMAJ)
 	@$(RM) $(LIBDIR)/$(DYMIN)
