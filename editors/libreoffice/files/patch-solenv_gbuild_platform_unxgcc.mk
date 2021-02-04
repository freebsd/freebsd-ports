--- solenv/gbuild/platform/unxgcc.mk.orig	2020-11-22 14:05:28 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -52,8 +52,7 @@ endif
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 	$(gb_CXX_LINKFLAGS) \
 
