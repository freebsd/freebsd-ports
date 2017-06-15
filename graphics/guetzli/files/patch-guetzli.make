--- guetzli.make.orig	2017-03-21 19:09:12 UTC
+++ guetzli.make
@@ -19,8 +19,8 @@ ifeq ($(config),release)
   INCLUDES += -I. -Ithird_party/butteraugli
   FORCE_INCLUDE +=
   ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
-  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -O3 -g `pkg-config --cflags libpng`
-  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -O3 -g -std=c++11 `pkg-config --cflags libpng`
+  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) `pkg-config --cflags libpng`
+  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -std=c++11 `pkg-config --cflags libpng`
   ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   LIBS +=
   LDDEPS +=
@@ -210,4 +210,4 @@ $(OBJDIR)/butteraugli.o: third_party/butteraugli/butte
 -include $(OBJECTS:%.o=%.d)
 ifneq (,$(PCH))
   -include $(OBJDIR)/$(notdir $(PCH)).d
-endif
\ No newline at end of file
+endif
