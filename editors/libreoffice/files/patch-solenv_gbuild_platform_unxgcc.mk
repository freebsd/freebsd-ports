--- solenv/gbuild/platform/unxgcc.mk.orig	2015-08-22 06:41:35 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -41,8 +41,7 @@ gb_CFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 
 
