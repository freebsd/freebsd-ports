--- build/gmake.freebsd/genie.make.orig	2023-09-20 17:46:05 UTC
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
@@ -52,20 +47,20 @@ ifeq ($(config),release)
   DEFINES            += -DNDEBUG -DLUA_COMPAT_MODULE -DLUA_USE_POSIX -DLUA_USE_DLOPEN
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -m64 -Wno-implicit-fallthrough
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Wno-implicit-fallthrough
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
-  ALL_LDFLAGS        += $(LDFLAGS) -L"." -s -rdynamic
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
 	$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o \
@@ -139,20 +134,20 @@ ifeq ($(config),debug)
   DEFINES            += -D_DEBUG -DLUA_COMPAT_MODULE -DLUA_USE_POSIX -DLUA_USE_DLOPEN
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g -m64 -Wno-implicit-fallthrough
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g -Wno-implicit-fallthrough
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
-  ALL_LDFLAGS        += $(LDFLAGS) -L"." -rdynamic
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
 	$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o \
