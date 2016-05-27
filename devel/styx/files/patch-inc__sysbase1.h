--- inc/sysbase1.h.orig	2003-12-09 15:36:56 UTC
+++ inc/sysbase1.h
@@ -193,7 +193,7 @@ AbstractType( DL_Hdl ); /* Abstract hand
 
 #define DL_LOAD_LAZY    0
 
-#if !defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H)))
+#if defined(__FreeBSD__) || (!defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H))))
 #define DL_LAZY         RTLD_LAZY
 #define DL_NOW          RTLD_NOW
 #define DL_BINDING_MASK RTLD_BINDING_MASK
