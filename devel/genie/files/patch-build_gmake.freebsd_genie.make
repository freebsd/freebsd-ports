--- build/gmake.freebsd/genie.make.orig	2026-03-25 18:20:17 UTC
+++ build/gmake.freebsd/genie.make
@@ -6,9 +6,8 @@ endif
   config=release
 endif
 
-ifndef verbose
-  SILENT = @
-endif
+verbose=1
+SILENT =
 
 SHELLTYPE := msdos
 ifeq (,$(ComSpec)$(COMSPEC))
@@ -31,10 +30,6 @@ endif
   RM    = $(SILENT) del /F "$(subst /,\\,$(1))" 2> nul || exit 0
 endif
 
-CC  = gcc
-CXX = g++
-AR  = ar
-
 ifndef RESCOMP
   ifdef WINDRES
     RESCOMP = $(WINDRES)
@@ -49,58 +44,24 @@ ifeq ($(config),release)
   OBJDIR              = obj/Release
   TARGETDIR           = ../../bin/bsd
   override TARGET              = $(TARGETDIR)/genie
-  DEFINES            += -DNDEBUG -DLUA_COMPAT_MODULE -DLUA_USE_POSIX -DLUA_USE_DLOPEN
-  INCLUDES           += -I"../../src/host/lua-5.3.0/src"
-  ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
-  ALL_LDFLAGS        += $(LDFLAGS) -L"." -s -rdynamic
+  DEFINES            += -DNDEBUG -DLUA_COMPAT_MODULE
+  ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES)
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES)
+  ALL_LDFLAGS        += --verbose $(LDFLAGS) -L"." -s -rdynamic
   LIBDEPS            +=
   LDDEPS             +=
   LDRESP              =
   LIBS               += $(LDDEPS) -lm
   EXTERNAL_LIBS      +=
   LINKOBJS            = $(OBJECTS)
-  LINKCMD             = $(CC) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
+  LINKCMD             = $(CC) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
   OBJRESP             =
   OBJECTS := \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lauxlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lbaselib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lbitlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lcode.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lcorolib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lctype.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldblib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldebug.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldo.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldump.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lfunc.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lgc.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/linit.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/liolib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/llex.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lmathlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lmem.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/loadlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lobject.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lopcodes.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/loslib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lparser.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lstate.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lstring.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lstrlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ltable.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ltablib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ltm.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lundump.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lutf8lib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lvm.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lzio.o \
 	$(OBJDIR)/src/host/os_chdir.o \
 	$(OBJDIR)/src/host/os_copyfile.o \
 	$(OBJDIR)/src/host/os_getcwd.o \
@@ -136,58 +97,24 @@ ifeq ($(config),debug)
   OBJDIR              = obj/Debug
   TARGETDIR           = ../../bin/bsd
   override TARGET              = $(TARGETDIR)/genie
-  DEFINES            += -D_DEBUG -DLUA_COMPAT_MODULE -DLUA_USE_POSIX -DLUA_USE_DLOPEN
-  INCLUDES           += -I"../../src/host/lua-5.3.0/src"
-  ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
-  ALL_LDFLAGS        += $(LDFLAGS) -L"." -rdynamic
+  DEFINES            += -D_DEBUG -DLUA_COMPAT_MODULE
+  ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES)
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES)
+  ALL_LDFLAGS        += --verbose $(LDFLAGS) -L"." -rdynamic
   LIBDEPS            +=
   LDDEPS             +=
   LDRESP              =
   LIBS               += $(LDDEPS) -lm
   EXTERNAL_LIBS      +=
   LINKOBJS            = $(OBJECTS)
-  LINKCMD             = $(CC) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
+  LINKCMD             = $(CC) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
   OBJRESP             =
   OBJECTS := \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lauxlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lbaselib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lbitlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lcode.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lcorolib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lctype.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldblib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldebug.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldo.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ldump.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lfunc.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lgc.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/linit.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/liolib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/llex.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lmathlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lmem.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/loadlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lobject.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lopcodes.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/loslib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lparser.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lstate.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lstring.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lstrlib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ltable.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ltablib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/ltm.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lundump.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lutf8lib.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lvm.o \
-	$(OBJDIR)/src/host/lua-5.3.0/src/lzio.o \
 	$(OBJDIR)/src/host/os_chdir.o \
 	$(OBJDIR)/src/host/os_copyfile.o \
 	$(OBJDIR)/src/host/os_getcwd.o \
@@ -222,7 +149,6 @@ OBJDIRS := \
 OBJDIRS := \
 	$(OBJDIR) \
 	$(OBJDIR)/src/host \
-	$(OBJDIR)/src/host/lua-5.3.0/src \
 
 RESOURCES := \
 
@@ -263,11 +189,11 @@ $(GCH): $(PCH) $(MAKEFILE) | $(OBJDIR)
 ifneq (,$(PCH))
 $(GCH): $(PCH) $(MAKEFILE) | $(OBJDIR)
 	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) -x c-header $(DEFINES) $(INCLUDES) -o "$@" -c "$<"
+	$(SILENT) $(CC) $(ALL_CFLAGS) -x c-header $(DEFINES) -o "$@" -c "$<"
 
 $(GCH_OBJC): $(PCH) $(MAKEFILE) | $(OBJDIR)
 	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_OBJCFLAGS) -x objective-c-header $(DEFINES) $(INCLUDES) -o "$@" -c "$<"
+	$(SILENT) $(CC) $(ALL_OBJCFLAGS) -x objective-c-header $(DEFINES) -o "$@" -c "$<"
 endif
 
 ifneq (,$(OBJRESP))
@@ -281,138 +207,6 @@ endif
 	$(SILENT) echo $^
 	$(SILENT) echo $^ > $@
 endif
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o: ../../src/host/lua-5.3.0/src/lapi.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lauxlib.o: ../../src/host/lua-5.3.0/src/lauxlib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lbaselib.o: ../../src/host/lua-5.3.0/src/lbaselib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lbitlib.o: ../../src/host/lua-5.3.0/src/lbitlib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lcode.o: ../../src/host/lua-5.3.0/src/lcode.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lcorolib.o: ../../src/host/lua-5.3.0/src/lcorolib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lctype.o: ../../src/host/lua-5.3.0/src/lctype.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/ldblib.o: ../../src/host/lua-5.3.0/src/ldblib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/ldebug.o: ../../src/host/lua-5.3.0/src/ldebug.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/ldo.o: ../../src/host/lua-5.3.0/src/ldo.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/ldump.o: ../../src/host/lua-5.3.0/src/ldump.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lfunc.o: ../../src/host/lua-5.3.0/src/lfunc.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lgc.o: ../../src/host/lua-5.3.0/src/lgc.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/linit.o: ../../src/host/lua-5.3.0/src/linit.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/liolib.o: ../../src/host/lua-5.3.0/src/liolib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/llex.o: ../../src/host/lua-5.3.0/src/llex.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lmathlib.o: ../../src/host/lua-5.3.0/src/lmathlib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lmem.o: ../../src/host/lua-5.3.0/src/lmem.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/loadlib.o: ../../src/host/lua-5.3.0/src/loadlib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lobject.o: ../../src/host/lua-5.3.0/src/lobject.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lopcodes.o: ../../src/host/lua-5.3.0/src/lopcodes.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/loslib.o: ../../src/host/lua-5.3.0/src/loslib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lparser.o: ../../src/host/lua-5.3.0/src/lparser.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lstate.o: ../../src/host/lua-5.3.0/src/lstate.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lstring.o: ../../src/host/lua-5.3.0/src/lstring.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lstrlib.o: ../../src/host/lua-5.3.0/src/lstrlib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/ltable.o: ../../src/host/lua-5.3.0/src/ltable.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/ltablib.o: ../../src/host/lua-5.3.0/src/ltablib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/ltm.o: ../../src/host/lua-5.3.0/src/ltm.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lundump.o: ../../src/host/lua-5.3.0/src/lundump.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lutf8lib.o: ../../src/host/lua-5.3.0/src/lutf8lib.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lvm.o: ../../src/host/lua-5.3.0/src/lvm.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
-
-$(OBJDIR)/src/host/lua-5.3.0/src/lzio.o: ../../src/host/lua-5.3.0/src/lzio.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host/lua-5.3.0/src
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -c "$<"
 
 $(OBJDIR)/src/host/os_chdir.o: ../../src/host/os_chdir.c $(GCH) $(MAKEFILE) | $(OBJDIR)/src/host
 	@echo $(notdir $<)
