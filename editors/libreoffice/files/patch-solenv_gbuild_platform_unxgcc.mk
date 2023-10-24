--- solenv/gbuild/platform/unxgcc.mk.orig	2023-09-22 19:07:01 UTC
+++ solenv/gbuild/platform/unxgcc.mk
@@ -17,6 +17,10 @@
 #   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 #
 
+ifneq ($(findstring lld,$(USE_LD)),)
+USE_LD += -Wl,--undefined-version
+endif
+
 # to block heavy exception handling that try to acquire the solarmutex
 export LO_LEAN_EXCEPTION=1
 
@@ -55,8 +59,7 @@ gb_CXXFLAGS := \
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
-	-Woverloaded-virtual \
+	$(CXXFLAGS_WARN) \
 	$(CXXFLAGS_CXX11) \
 	$(gb_CXX_LINKFLAGS) \
 
