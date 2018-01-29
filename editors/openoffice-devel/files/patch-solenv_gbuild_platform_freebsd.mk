--- solenv/gbuild/platform/freebsd.mk.orig	2018-01-25 18:01:47 UTC
+++ solenv/gbuild/platform/freebsd.mk
@@ -95,6 +95,7 @@ gb_CXXFLAGS := \
 	-fno-use-cxa-atexit \
 	-fvisibility-inlines-hidden \
 	-fvisibility=hidden \
+	-std=gnu++98 \
 	-pipe
 ifeq ($(COM),CLANG)
 gb_CXXFLAGS += -DHAVE_STL_INCLUDE_PATH
@@ -143,6 +144,12 @@ gb_LinkTarget_LDFLAGS += \
 	-Wl,--dynamic-list-cpp-typeinfo \
 	-Wl,-Bsymbolic-functions \
 
+endif
+
+ifneq ($(filter $(CPUNAME),INTEL X86_64),)
+gb_CFLAGS += -fstack-protector
+gb_CXXFLAGS += -fstack-protector
+gb_LinkTarget_LDFLAGS += -fstack-protector
 endif
 
 ifeq ($(gb_DEBUGLEVEL),2)
