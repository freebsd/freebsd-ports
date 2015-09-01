--- solenv/gbuild/platform/unxgcc.mk.orig	2015-08-22 06:41:35 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -41,7 +41,7 @@ gb_CFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
+	-Wno-unused-parameter \
 	-Woverloaded-virtual \
 	$(CXXFLAGS_CXX11) \
 
