--- inc/sysbase1.h.orig	Tue Apr 17 00:55:58 2001
+++ inc/sysbase1.h	Tue Apr 17 00:57:17 2001
@@ -178,7 +178,7 @@
 
 #define DL_LOAD_LAZY    0
 
-#if !defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H)))
+#if defined(__FreeBSD__) || (!defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H))))
 #define DL_LAZY         RTLD_LAZY
 #define DL_NOW          RTLD_NOW
 #define DL_BINDING_MASK RTLD_BINDING_MASK
