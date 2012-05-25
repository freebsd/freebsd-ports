--- build/premake/premake4/build/gmake.unix/Premake4.make.orig	2012-01-12 01:03:37.000000000 +0100
+++ build/premake/premake4/build/gmake.unix/Premake4.make	2012-05-03 16:24:21.478971350 +0200
@@ -24,12 +24,12 @@
   TARGETDIR  = ../../bin/release
   TARGET     = $(TARGETDIR)/premake4
   DEFINES   += -DNDEBUG -DLUA_USE_POSIX -DLUA_USE_DLOPEN
-  INCLUDES  += -I../../src/host/lua-5.1.4/src
+  INCLUDES  += -I../../src/host/lua-5.1.4/src -I$(LOCALBASE)/include/wx-2.8
   CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
   CFLAGS    += $(CPPFLAGS) -Wall -Os
   CXXFLAGS  += $(CFLAGS) 
   LDFLAGS   += -s -rdynamic
-  LIBS      += -lm -ldl 
+  LIBS      += -lm 
   RESFLAGS  += $(DEFINES) $(INCLUDES) 
   LDDEPS    += 
   LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(LDDEPS) $(LIBS)
@@ -46,12 +46,12 @@
   TARGETDIR  = ../../bin/debug
   TARGET     = $(TARGETDIR)/premake4
   DEFINES   += -D_DEBUG -DLUA_USE_POSIX -DLUA_USE_DLOPEN
-  INCLUDES  += -I../../src/host/lua-5.1.4/src
+  INCLUDES  += -I../../src/host/lua-5.1.4/src -I$(LOCALBASE)/include/wx-2.8
   CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
   CFLAGS    += $(CPPFLAGS) -Wall -g
   CXXFLAGS  += $(CFLAGS) 
   LDFLAGS   += -rdynamic
-  LIBS      += -lm -ldl 
+  LIBS      += -lm
   RESFLAGS  += $(DEFINES) $(INCLUDES) 
   LDDEPS    += 
   LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(LDDEPS) $(LIBS)
