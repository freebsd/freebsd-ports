--- mk/platform.mk.orig	2012-12-25 08:33:07.971922333 +0800
+++ mk/platform.mk	2012-12-25 08:33:16.996994081 +0800
@@ -222,7 +222,7 @@
   ifeq ($(origin CPP),default)
     CPP=clang -E
   endif
-  CFG_GCCISH_CFLAGS += -Wall -Werror -g
+  CFG_GCCISH_CFLAGS += -Wall -g
   CFG_GCCISH_CXXFLAGS += -fno-rtti
   CFG_GCCISH_LINK_FLAGS += -g
   # These flags will cause the compiler to produce a .d file
@@ -268,7 +268,7 @@
   ifeq ($(origin CPP),default)
     CPP=gcc -E
   endif
-  CFG_GCCISH_CFLAGS += -Wall -Werror -g
+  CFG_GCCISH_CFLAGS += -Wall -g
   CFG_GCCISH_CXXFLAGS += -fno-rtti
   CFG_GCCISH_LINK_FLAGS += -g
   # These flags will cause the compiler to produce a .d file
@@ -322,4 +322,4 @@
 endef
 
 $(foreach target,$(CFG_TARGET_TRIPLES),\
-  $(eval $(call CFG_MAKE_ASSEMBLER,$(target))))
\ No newline at end of file
+  $(eval $(call CFG_MAKE_ASSEMBLER,$(target))))
