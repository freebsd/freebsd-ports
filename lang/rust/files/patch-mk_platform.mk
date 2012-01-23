--- mk/platform.mk.orig	2012-01-22 08:59:58.097803422 +0800
+++ mk/platform.mk	2012-01-22 04:45:22.124872578 +0800
@@ -188,7 +188,7 @@
   CC=clang
   CXX=clang++
   CPP=cpp
-  CFG_GCCISH_CFLAGS += -Wall -Werror -fno-rtti -g
+  CFG_GCCISH_CFLAGS += -Wall -Werror -Wno-c++11-compat -fno-rtti -g
   CFG_GCCISH_LINK_FLAGS += -g
   CFG_DEPEND_C = $(CFG_GCCISH_CROSS)$(CXX) $(CFG_GCCISH_CFLAGS) -MT "$(1)" \
     -MM $(2)
