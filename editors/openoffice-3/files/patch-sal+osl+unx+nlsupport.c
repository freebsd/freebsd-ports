--- ../sal/osl/unx/nlsupport.c.orig	Tue May 21 15:22:11 2002
+++ ../sal/osl/unx/nlsupport.c	Sat Jul 20 22:42:15 2002
@@ -63,7 +63,7 @@
 #include <osl/diagnose.h>
 #include <osl/process.h>
 
-#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD) || defined(FREEBSD)
 #include <pthread.h>
 #include <locale.h>
 #include <langinfo.h>
@@ -241,7 +241,7 @@
     return NULL;
 }
         
-#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD) || defined(FREEBSD)
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -254,7 +254,7 @@
  * XXX this code has the usual mt problems aligned with setlocale() XXX
  */
 
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD) || defined(FREEBSD)
 #if !defined(CODESET)
 #define CODESET _NL_CTYPE_CODESET_NAME
 #endif
@@ -315,7 +315,7 @@
    { "sjis",		RTL_TEXTENCODING_SHIFT_JIS	}, /* Japan */
 };
 
-#elif defined(LINUX) || defined(NETBSD)
+#elif defined(LINUX) || defined(NETBSD) || defined(FREEBSD)
 
 const _pair _nl_language_list[] = {
     { "ANSI_X3.110-1983",           RTL_TEXTENCODING_DONTKNOW   },  /* ISO-IR-99 NAPLPS */
@@ -496,7 +496,7 @@
     { "WIN-SAMI-2",                 RTL_TEXTENCODING_DONTKNOW }     /* WS2 */
 };
 
-#endif /* ifdef LINUX || NETBSD */
+#endif /* ifdef LINUX || NETBSD || FREEBSD */
 
 static pthread_mutex_t aLocalMutex = PTHREAD_MUTEX_INITIALIZER;
 
@@ -618,7 +618,7 @@
     return ret;
 }
 
-#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD */
+#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD || FREEBSD */
 
 /*
  * FIXME: the MacOS X implemetation is missing
@@ -651,7 +651,7 @@
     return 0;
 }
 
-#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -887,6 +887,6 @@
     return 0;
 }
 
-#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 
