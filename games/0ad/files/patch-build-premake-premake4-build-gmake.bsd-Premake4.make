--- build/premake/premake4/build/gmake.bsd/Premake4.make.orig	2012-09-13 04:29:58.196744551 +0200
+++ build/premake/premake4/build/gmake.bsd/Premake4.make	2012-09-13 04:32:48.083760584 +0200
@@ -24,7 +24,7 @@
   TARGETDIR  = ../../bin/release
   TARGET     = $(TARGETDIR)/premake4
   DEFINES   += -DNDEBUG -DLUA_USE_POSIX -DLUA_USE_DLOPEN
-  INCLUDES  += -I../../src/host/lua-5.1.4/src
+  INCLUDES  += -I../../src/host/lua-5.1.4/src -I$(LOCALBASE)/include/wx-2.8
   CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
   CFLAGS    += $(CPPFLAGS) -Wall -Os
   CXXFLAGS  += $(CPPFLAGS) -Wall -Os
@@ -46,7 +46,7 @@
   TARGETDIR  = ../../bin/debug
   TARGET     = $(TARGETDIR)/premake4
   DEFINES   += -D_DEBUG -DLUA_USE_POSIX -DLUA_USE_DLOPEN
-  INCLUDES  += -I../../src/host/lua-5.1.4/src
+  INCLUDES  += -I../../src/host/lua-5.1.4/src -I$(LOCALBASE)/include/wx-2.8
   CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
   CFLAGS    += $(CPPFLAGS) -Wall -g
   CXXFLAGS  += $(CPPFLAGS) -Wall -g
