--- ./solenv/gbuild/platform/unxgcc.mk.orig	2013-02-19 19:39:23.000000000 -0500
+++ ./solenv/gbuild/platform/unxgcc.mk	2013-02-19 19:35:41.000000000 -0500
@@ -53,7 +53,7 @@
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
+	-Wno-unused-parameter \
 	-Wsign-promo \
 	-Woverloaded-virtual \
 
