--- solenv/gbuild/platform/unxgcc.mk.orig	2013-12-11 01:11:21.000000000 +0900
+++ solenv/gbuild/platform/unxgcc.mk	2014-01-29 17:09:01.000000000 +0900
@@ -48,7 +48,7 @@
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
+	-Wno-unused-parameter \
 	-Woverloaded-virtual \
 
 ifneq ($(COM_GCC_IS_CLANG),TRUE)
