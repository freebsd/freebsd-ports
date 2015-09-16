--- build/premake/bsd/Premake4.make.orig	2011-10-20 19:58:38 UTC
+++ build/premake/bsd/Premake4.make
@@ -26,13 +26,13 @@ ifeq ($(config),release)
   DEFINES   += -DNDEBUG
   INCLUDES  += -I../4.3/src/host/lua-5.1.4/src
   CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
-  CFLAGS    += $(CPPFLAGS) $(ARCH) -Wall -Os
+  CFLAGS    += $(CPPFLAGS) -Wall -Os
   CXXFLAGS  += $(CFLAGS) 
   LDFLAGS   += -s -rdynamic
-  LIBS      += 
+  LIBS      += -lm
   RESFLAGS  += $(DEFINES) $(INCLUDES) 
   LDDEPS    += 
-  LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
+  LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(LIBS)
   define PREBUILDCMDS
   endef
   define PRELINKCMDS
@@ -48,13 +48,13 @@ ifeq ($(config),debug)
   DEFINES   += -D_DEBUG
   INCLUDES  += -I../4.3/src/host/lua-5.1.4/src
   CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
-  CFLAGS    += $(CPPFLAGS) $(ARCH) -Wall -g
+  CFLAGS    += $(CPPFLAGS) -Wall -g
   CXXFLAGS  += $(CFLAGS) 
   LDFLAGS   += -rdynamic
   LIBS      += 
   RESFLAGS  += $(DEFINES) $(INCLUDES) 
   LDDEPS    += 
-  LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
+  LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(LIBS)
   define PREBUILDCMDS
   endef
   define PRELINKCMDS
