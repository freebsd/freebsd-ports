--- solenv/gbuild/platform/unxgcc.mk.orig	2022-12-22 00:14:09 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -55,8 +55,7 @@ gb_CXXFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 	$(gb_CXX_LINKFLAGS) \
 
