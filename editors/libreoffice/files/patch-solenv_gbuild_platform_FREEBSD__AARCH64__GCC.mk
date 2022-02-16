--- solenv/gbuild/platform/FREEBSD_AARCH64_GCC.mk.orig	2022-01-26 14:35:29 UTC
+++ solenv/gbuild/platform/FREEBSD_AARCH64_GCC.mk
@@ -9,6 +9,8 @@
 
 #please make generic modifications to unxgcc.mk
 
+gb_STDLIBS := $(PTHREAD_LIBS)
+
 include $(GBUILDDIR)/platform/unxgcc.mk
 
 # vim: set noet sw=4:
