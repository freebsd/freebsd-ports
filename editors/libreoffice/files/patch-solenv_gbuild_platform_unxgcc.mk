--- solenv/gbuild/platform/unxgcc.mk.orig	2016-10-28 14:50:26 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -44,8 +44,7 @@ gb_CFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 
 
