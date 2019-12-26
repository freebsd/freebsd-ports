--- build/FreeBSD.gcc.inc.orig	2019-12-20 22:46:13 UTC
+++ build/FreeBSD.gcc.inc
@@ -26,7 +26,7 @@ WARNING_SUPPRESS = -Wno-parentheses
 
 CPLUS = g++ 
 CONLY = gcc
-LIB_LINK_FLAGS = -shared
+LIB_LINK_FLAGS = -shared -Wl,-soname=$(BUILDING_LIBRARY)
 LIBS = -lpthread 
 C_FLAGS = $(CPLUS_FLAGS)
 
@@ -56,6 +56,11 @@ ifeq (ia64,$(arch))
 endif 
 
 ifeq (intel64,$(arch))
+    CPLUS_FLAGS += -m64
+    LIB_LINK_FLAGS += -m64
+endif 
+
+ifeq (powerpc64,$(arch))
     CPLUS_FLAGS += -m64
     LIB_LINK_FLAGS += -m64
 endif 
