--- libbase/sysbase1.c.orig	Sun Feb 25 22:36:20 2001
+++ libbase/sysbase1.c	Tue Apr 17 01:25:49 2001
@@ -526,7 +526,7 @@
 #define DL_LOAD_LAZY    0
 
 /*DOC_INTERFACE*/
-#if !defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H)))
+#if defined(__FreeBSD__) || (!defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H))))
 #define DL_LAZY         RTLD_LAZY
 #define DL_NOW          RTLD_NOW
 #define DL_BINDING_MASK RTLD_BINDING_MASK
@@ -570,7 +570,7 @@
   }
 
 #else
-#if !defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || ( defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H) ) )
+#if defined(__FreeBSD__) || (!defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || ( defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H) ) ) )
 
 DL_Hdl DL_open(string dlname, int flag)
 /* loads dll 'dlname' in mode 'flag' ( ERROR: NULL )
