--- solenv/gbuild/platform/FREEBSD_POWERPC64_GCC.mk.orig	2022-01-26 14:35:29 UTC
+++ solenv/gbuild/platform/FREEBSD_POWERPC64_GCC.mk
@@ -11,6 +11,7 @@
 gb_CPUDEFS += -DPPC -DPOWERPC64
 gb_COMPILERDEFAULTOPTFLAGS := -O2
 gb_CXXFLAGS += -mminimal-toc
+gb_STDLIBS := $(PTHREAD_LIBS)
 
 include $(GBUILDDIR)/platform/unxgcc.mk
 
