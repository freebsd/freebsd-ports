--- vcl/unx/source/app/vsound.hxx.orig	Sun Jul 21 00:10:24 2002
+++ vcl/unx/source/app/vsound.hxx	Sun Jul 21 00:10:27 2002
@@ -61,7 +61,7 @@
 #ifndef _VCL_VSOUND_HXX
 #define _VCL_VSOUND_HXX
 
-#ifdef LINUX
+#if defined(LINUX) || defined(FREEBSD)
 #define USE_OSS
 #endif
 
@@ -69,7 +69,7 @@
 #define USE_DEVAUDIO
 #endif
 
-#if defined LINUX || defined SOLARIS
+#if defined (LINUX) || defined(FREEBSD) || defined (SOLARIS)
 #define USE_NAS
 #endif
 
