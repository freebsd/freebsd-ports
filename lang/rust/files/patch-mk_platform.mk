--- mk/platform.mk.orig	2012-04-05 22:34:59.678608449 +0800
+++ mk/platform.mk	2012-04-05 22:35:13.749110633 +0800
@@ -213,7 +213,7 @@
   ifeq ($(origin CPP),default)
     CPP=cpp
   endif
-  CFG_GCCISH_CFLAGS += -Wall -Werror -fno-rtti -g
+  CFG_GCCISH_CFLAGS += -Wall -fno-rtti -g
   CFG_GCCISH_LINK_FLAGS += -g
   CFG_DEPEND_C = $(CFG_GCCISH_CROSS)$(CXX) $(CFG_GCCISH_CFLAGS) -MT "$(1)" \
     -MM $(2)
@@ -244,7 +244,7 @@
   ifeq ($(origin CPP),default)
     CPP=cpp
   endif
-  CFG_GCCISH_CFLAGS += -Wall -Werror -fno-rtti -g
+  CFG_GCCISH_CFLAGS += -Wall -fno-rtti -g
   CFG_GCCISH_LINK_FLAGS += -g
   CFG_DEPEND_C = $(CFG_GCCISH_CROSS)$(CXX) $(CFG_GCCISH_CFLAGS) -MT "$(1)" \
     -MM $(2)
