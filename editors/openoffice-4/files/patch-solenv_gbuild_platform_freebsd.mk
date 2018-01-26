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
@@ -142,6 +143,12 @@ gb_LinkTarget_LDFLAGS += \
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
