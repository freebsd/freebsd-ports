--- solenv/gbuild/platform/FREEBSD_INTEL_GCC.mk.orig	2022-01-26 14:35:29 UTC
+++ solenv/gbuild/platform/FREEBSD_INTEL_GCC.mk
@@ -10,6 +10,7 @@
 #please make generic modifications to unxgcc.mk
 
 gb_CPUDEFS := -DX86
+gb_STDLIBS := $(PTHREAD_LIBS)
 
 include $(GBUILDDIR)/platform/unxgcc.mk
 
