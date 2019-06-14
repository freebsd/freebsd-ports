--- build/gmake.freebsd/genie.make.orig	2018-11-08 16:01:03 UTC
+++ build/gmake.freebsd/genie.make
@@ -49,17 +49,17 @@ ifeq ($(config),release)
   DEFINES            += -DNDEBUG -DLUA_COMPAT_MODULE -DLUA_USE_POSIX -DLUA_USE_DLOPEN
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -Os
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -Os
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -Os
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -Os
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -Os
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   ALL_LDFLAGS        += $(LDFLAGS) -L. -s -rdynamic
   LDDEPS             +=
   LIBS               += $(LDDEPS) -lm
   EXTERNAL_LIBS      +=
-  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
+  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -g
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -g
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -g
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -g
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) -Wall -Wextra -g
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   ALL_LDFLAGS        += $(LDFLAGS) -L. -rdynamic
   LDDEPS             +=
   LIBS               += $(LDDEPS) -lm
   EXTERNAL_LIBS      +=
-  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
+  LINKCMD             = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
   OBJECTS := \
 	$(OBJDIR)/src/host/lua-5.3.0/src/lapi.o \
 	$(OBJDIR)/src/host/lua-5.3.0/src/lauxlib.o \
