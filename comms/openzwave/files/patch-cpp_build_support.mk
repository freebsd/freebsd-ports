# Allow DOXYGEN (DOCS) and DOT to be conditionally disabled
# Respect/Honour user *FLAGS
# Build verbose by default
# TODO: Upstream

--- cpp/build/support.mk.orig	2019-03-27 04:31:27 UTC
+++ cpp/build/support.mk
@@ -23,10 +23,14 @@ ifeq ($(UNAME),Darwin)
 DARWIN_VERSION := $(shell sw_vers -productVersion)
 DARWIN_MOJAVE_UP := $(shell expr $(DARWIN_VERSION) \>= 10.14)
 endif
+ifeq ($(ENABLE_DOCS),1)
 #the location of Doxygen to generate our api documentation
 DOXYGEN := $(shell which doxygen)
+ifeq ($(ENABLE_DOT),1)
 #dot is required for doxygen (part of Graphviz)
 DOT := $(shell which dot)
+endif
+endif
 #the machine type we are building on (i686 or x86_64)
 MACHINE := $(shell uname -m)
 #the location of xmllink for checking our config files
@@ -89,11 +93,11 @@ SED    := sed
 
 #determine if we are release or debug Build and set appropriate flags
 ifeq ($(BUILD), release)
-CFLAGS	+= -c $(RELEASE_CFLAGS)
-LDFLAGS	+= $(RELEASE_LDFLAGS)
+CFLAGS	:= -c $(RELEASE_CFLAGS) $(CFLAGS)
+LDFLAGS	:= $(RELEASE_LDFLAGS) $(LDFLAGS)
 else
-CFLAGS	+= -c $(DEBUG_CFLAGS)
-LDFLAGS	+= $(DEBUG_LDFLAGS)
+CFLAGS	:= -c $(DEBUG_CFLAGS) $(CFLAGS)
+LDFLAGS	:= $(DEBUG_LDFLAGS) $(LDFLAGS)
 endif
 
 #if /lib64 exists, then setup x86_64 library path to lib64 (good indication if a linux has /lib and lib64). 
@@ -143,24 +147,24 @@ endif
 
 $(OBJDIR)/%.o : %.cpp
 	@echo "Building $(notdir $@)"
-	@$(CXX) -MM $(CFLAGS) $(INCLUDES) $< > $(DEPDIR)/$*.d
+	$(CXX) -MM $(CFLAGS) $(INCLUDES) $< > $(DEPDIR)/$*.d
 	@mv -f $(DEPDIR)/$*.d $(DEPDIR)/$*.d.tmp
 	@$(SED) -e 's|.*:|$(OBJDIR)/$*.o: $(DEPDIR)/$*.d|' < $(DEPDIR)/$*.d.tmp > $(DEPDIR)/$*.d;
 	@$(SED) -e 's/.*://' -e 's/\\$$//' < $(DEPDIR)/$*.d.tmp | $(FMTCMD) | \
 	  $(SED) -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/.$*.d;
 	@rm -f $(DEPDIR)/$*.d.tmp
-	@$(CXX) $(CFLAGS) $(TARCH) $(INCLUDES) -o $@ $<
+	$(CXX) $(CFLAGS) $(TARCH) $(INCLUDES) -o $@ $<
 
 
 $(OBJDIR)/%.o : %.c
 	@echo "Building $(notdir $@)"	
-	@$(CC) -MM $(CFLAGS) $(INCLUDES) $< > $(DEPDIR)/$*.d
+	$(CC) -MM $(CFLAGS) $(INCLUDES) $< > $(DEPDIR)/$*.d
 	@mv -f $(DEPDIR)/$*.d $(DEPDIR)/$*.d.tmp
 	@$(SED) -e 's|.*:|$(OBJDIR)/$*.o: $(DEPDIR)/$*.d|' < $(DEPDIR)/$*.d.tmp > $(DEPDIR)/$*.d;
 	@$(SED) -e 's/.*://' -e 's/\\$$//' < $(DEPDIR)/$*.d.tmp | $(FMTCMD) | \
 	  $(SED) -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/.$*.d;
 	@rm -f $(DEPDIR)/$*.d.tmp
-	@$(CC) $(CFLAGS) $(TARCH) $(INCLUDES) -o $@ $<
+	$(CC) $(CFLAGS) $(TARCH) $(INCLUDES) -o $@ $<
 
 
 dummy := $(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
