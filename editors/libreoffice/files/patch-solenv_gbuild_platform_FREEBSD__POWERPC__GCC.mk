--- solenv/gbuild/platform/FREEBSD_POWERPC_GCC.mk.orig	2022-01-26 14:35:29 UTC
+++ solenv/gbuild/platform/FREEBSD_POWERPC_GCC.mk
@@ -10,6 +10,7 @@
 #please make generic modifications to unxgcc.mk or linux.mk
 gb_CPUDEFS += -DPPC -DPOWERPC
 gb_COMPILERDEFAULTOPTFLAGS := -O2
+gb_STDLIBS := $(PTHREAD_LIBS)
 
 include $(GBUILDDIR)/platform/unxgcc.mk
 
