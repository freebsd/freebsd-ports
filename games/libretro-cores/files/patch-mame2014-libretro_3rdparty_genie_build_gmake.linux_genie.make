--- mame2014-libretro/3rdparty/genie/build/gmake.linux/genie.make.orig	2015-11-04 17:31:20 UTC
+++ mame2014-libretro/3rdparty/genie/build/gmake.linux/genie.make
@@ -50,7 +50,7 @@ ifeq ($(config),release)
   ALL_RESFLAGS  += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   ALL_LDFLAGS   += $(LDFLAGS) -L. -s -rdynamic
   LDDEPS    +=
-  LIBS      += $(LDDEPS) -ldl -lm
+  LIBS      += $(LDDEPS) -lm
   LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
   OBJECTS := \
 	$(OBJDIR)/src/host/os_getcwd.o \
@@ -126,7 +126,7 @@ ifeq ($(config),debug)
   ALL_RESFLAGS  += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   ALL_LDFLAGS   += $(LDFLAGS) -L. -rdynamic
   LDDEPS    +=
-  LIBS      += $(LDDEPS) -ldl -lm
+  LIBS      += $(LDDEPS) -lm
   LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)
   OBJECTS := \
 	$(OBJDIR)/src/host/os_getcwd.o \
