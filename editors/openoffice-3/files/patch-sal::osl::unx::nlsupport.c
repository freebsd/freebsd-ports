--- ../sal/osl/unx/nlsupport.c.orig	Sat Mar  9 00:51:17 2002
+++ ../sal/osl/unx/nlsupport.c	Sat Mar  9 01:54:43 2002
@@ -63,11 +63,17 @@
 #include <osl/diagnose.h>
 #include <osl/process.h>
 
-#if defined(LINUX) || defined(SOLARIS)
+#if defined(LINUX) || defined(SOLARIS) || defined(NETBSD) || defined(FREEBSD)
 #include <pthread.h>
 #include <locale.h>
+#if defined(FREEBSD)
+#if OSVERSION > 500000
 #include <langinfo.h>
 #endif
+#else
+#include <langinfo.h>
+#endif
+#endif
 
 /*****************************************************************************/
 /* typedefs
@@ -242,7 +248,7 @@
     return NULL;
 }
         
-#if defined(LINUX) || defined(SOLARIS)
+#if defined(LINUX) || defined(SOLARIS) || defined(NETBSD) || defined(FREEBSD)
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -296,7 +302,7 @@
 /* XXX MS-874 is an extension to tis620, so this is not
  * really equivalent */
 
-#elif defined(LINUX)
+#elif defined(LINUX) || defined(NETBSD) || defined(FREEBSD)
 
 const _pair _nl_language_list[] = {
     { "ANSI_X3.110-1983",           RTL_TEXTENCODING_DONTKNOW   },  /* ISO-IR-99 NAPLPS */
@@ -477,7 +483,7 @@
     { "WIN-SAMI-2",                 RTL_TEXTENCODING_DONTKNOW }     /* WS2 */
 };
 
-#endif /* ifdef LINUX */
+#endif /* ifdef LINUX || NETBSD || FREEBSD */
 
 static pthread_mutex_t aLocalMutex = PTHREAD_MUTEX_INITIALIZER;
 
@@ -516,7 +522,13 @@
     }
         
     /* get the charset as indicated by the LC_CTYPE locale */
+#if defined(NETBSD) || defined(FREEBSD)
+#if !defined(CODESET) 
+    codeset = NULL;
+#else
     codeset = nl_langinfo( CODESET );
+#endif
+#endif
 
     if ( codeset != NULL )
     {
@@ -595,7 +607,7 @@
     return ret;
 }
 
-#elif defined(MACOSX) /* ifdef LINUX || SOLARIS */
+#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD || FREEBSD */
 
 /*
  * FIXME: the MacOS X implemetation is missing
@@ -628,7 +640,7 @@
     return 0;
 }
 
-#else /* ifdef LINUX || SOLARIS || MACOSX */
+#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -844,6 +856,6 @@
     return 0;
 }
 
-#endif /* ifdef LINUX || SOLARIS || MACOSX*/
+#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 
