--- libbase/sysbase1.c.orig	2003-12-09 16:37:07.000000000 +0100
+++ libbase/sysbase1.c	2013-02-08 15:35:31.000000000 +0100
@@ -521,7 +521,7 @@
 }
 
 #else
-#if !defined( MSDOS ) && defined ( __GNUC__ ) && #cpu (i386)
+#if !defined( MSDOS ) && defined ( __GNUC__ ) && defined(__i386__)
 #define PUSH_FUN_ARG(arg) __asm__ volatile ( "pushl %0" : : "r" (arg) )
 #define CALL_FUN(f)       __asm__ volatile ( "call *%0" : : "r" (f) )
 
@@ -550,7 +550,7 @@
 #define DL_LOAD_LAZY    0
 
 /*DOC_INTERFACE*/
-#if !defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H)))
+#if defined(__FreeBSD__) || (!defined(STYX_CONFIG_OSMS) && (!defined(HAVE_CONFIG_H) || (defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H))))
 #define DL_LAZY         RTLD_LAZY
 #define DL_NOW          RTLD_NOW
 #define DL_BINDING_MASK RTLD_BINDING_MASK
@@ -594,7 +594,7 @@
   }
 
 #else
-#if !defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || ( defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H) ) )
+#if defined(__FreeBSD__) || (!defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || ( defined(HAVE_LIBDL) && defined(HAVE_DLFCN_H) ) ) )
 
 DL_Hdl DL_open(string dlname, int flag)
 /* loads dll 'dlname' in mode 'flag' ( ERROR: NULL )
