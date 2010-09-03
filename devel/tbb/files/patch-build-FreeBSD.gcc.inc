--- build/FreeBSD.gcc.inc.orig	2010-08-28 00:14:43.080234020 +0200
+++ build/FreeBSD.gcc.inc	2010-08-28 00:14:53.400821755 +0200
@@ -37,7 +37,7 @@
 
 TBB_NOSTRICT = 1
 
-CPLUS = g++ 
+#CPLUS = g++ 
 CONLY = gcc
 LIB_LINK_FLAGS = -shared
 LIBS = -lpthread 
