--- build/FreeBSD.gcc.inc.orig	2016-11-18 13:37:51.743639461 +0000
+++ build/FreeBSD.gcc.inc	2016-11-18 13:41:28.615767655 +0000
@@ -30,7 +30,7 @@
 
 CPLUS = g++ 
 CONLY = gcc
-LIB_LINK_FLAGS = -shared
+LIB_LINK_FLAGS = -shared -Wl,-soname=$(BUILDING_LIBRARY)
 LIBS = -lpthread 
 C_FLAGS = $(CPLUS_FLAGS)
 
