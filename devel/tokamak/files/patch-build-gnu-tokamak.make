--- build/gnu/tokamak.make.orig	2008-06-24 00:30:13.000000000 +0400
+++ build/gnu/tokamak.make	2008-06-24 00:31:55.000000000 +0400
@@ -2,7 +2,7 @@
 # Don't edit this file! Instead edit `premake.lua` then rerun `make`
 
 ifndef CONFIG
-  CONFIG=Debug
+  CONFIG=Release
 endif
 
 ifeq ($(CONFIG),Debug)
@@ -25,9 +25,9 @@
   LIBDIR := ../../lib
   OBJDIR := obj/Release
   OUTDIR := ../../lib
-  CPPFLAGS := -MMD -D "WIN32" -D "_LIB" -D "_CRT_SECURE_NO_DEPRECATE" -D "NDEBUG" -I "../../include/"
-  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -O2
-  CXXFLAGS := $(CFLAGS) --no-exceptions --no-rtti
+  CPPFLAGS += -I "../../include/"
+  CFLAGS += $(CPPFLAGS)
+  CXXFLAGS += $(CPPFLAGS) -fno-exceptions -fno-rtti
   LDFLAGS += -L$(BINDIR) -L$(LIBDIR) -s
   LDDEPS :=
   RESFLAGS := -D "WIN32" -D "_LIB" -D "_CRT_SECURE_NO_DEPRECATE" -D "NDEBUG" -I "../../include/"
@@ -44,7 +44,7 @@
 	$(OBJDIR)/dcd.o \
 	$(OBJDIR)/lines.o \
 	$(OBJDIR)/ne_interface.o \
-	$(OBJDIR)/perfwin32.o \
+	$(OBJDIR)/perflinux.o \
 	$(OBJDIR)/region.o \
 	$(OBJDIR)/restcontact.o \
 	$(OBJDIR)/rigidbody.o \
@@ -139,7 +139,7 @@
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -o $@ -c $<
 
-$(OBJDIR)/perfwin32.o: ../../tokamaksrc/src/perfwin32.cpp
+$(OBJDIR)/perflinux.o: ../../tokamaksrc/src/perflinux.cpp
 	-@$(CMD_MKOBJDIR)
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -o $@ -c $<
