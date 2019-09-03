--- build/FreeBSD.gcc.inc.orig	2019-03-21 15:28:21 UTC
+++ build/FreeBSD.gcc.inc
@@ -60,6 +60,11 @@ ifeq (ia64,$(arch))
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
