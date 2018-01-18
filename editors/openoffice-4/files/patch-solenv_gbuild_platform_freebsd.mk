--- solenv/gbuild/platform/freebsd.mk.orig	2017-11-27 13:50:25 UTC
+++ solenv/gbuild/platform/freebsd.mk
@@ -94,6 +94,7 @@ gb_CXXFLAGS := \
 	-fno-use-cxa-atexit \
 	-fvisibility-inlines-hidden \
 	-fvisibility=hidden \
+	-std=gnu++98 \
 	-pipe
 ifeq ($(COM),CLANG)
 gb_CXXFLAGS += -DHAVE_STL_INCLUDE_PATH
