--- 3rdparty/genie/build/gmake.freebsd/genie.make.orig	2023-05-26 04:14:50 UTC
+++ 3rdparty/genie/build/gmake.freebsd/genie.make
@@ -28,9 +28,9 @@ endif
   RM    = $(SILENT) del /F "$(subst /,\\,$(1))" 2> nul || exit 0
 endif
 
-CC  = gcc
-CXX = g++
-AR  = ar
+CC  ?= gcc
+CXX ?= g++
+AR  ?= ar
 
 ifndef RESCOMP
   ifdef WINDRES
@@ -49,17 +49,17 @@ ifeq ($(config),release)
   DEFINES            += -DNDEBUG -DLUA_COMPAT_MODULE -DLUA_USE_POSIX -DLUA_USE_DLOPEN
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Os $(MPARAM)
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Os $(MPARAM)
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Os $(MPARAM)
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Os $(MPARAM)
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -Os $(MPARAM)
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   ALL_LDFLAGS        += $(LDFLAGS) -L. -s -rdynamic
   LDDEPS             +=
   LIBS               += $(LDDEPS) -lm
   EXTERNAL_LIBS      +=
-  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
+  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES)  $(ALL_LDFLAGS) $(LIBS)
   OBJECTS := \
 	$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o \
 	$(OBJDIR)/src/host/lua-5.3.0/src/lauxlib.o \
@@ -132,17 +132,17 @@ ifeq ($(config),debug)
   DEFINES            += -D_DEBUG -DLUA_COMPAT_MODULE -DLUA_USE_POSIX -DLUA_USE_DLOPEN
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -g
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)  -Wall -Wextra -g
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   ALL_LDFLAGS        += $(LDFLAGS) -L. -rdynamic
   LDDEPS             +=
   LIBS               += $(LDDEPS) -lm
   EXTERNAL_LIBS      +=
-  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
+  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES)  $(ALL_LDFLAGS) $(LIBS)
   OBJECTS := \
 	$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o \
 	$(OBJDIR)/src/host/lua-5.3.0/src/lauxlib.o \
