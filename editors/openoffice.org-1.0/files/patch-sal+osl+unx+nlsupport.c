--- ../sal/osl/unx/nlsupport.c.orig	Sun Mar 17 12:48:42 2002
+++ ../sal/osl/unx/nlsupport.c	Wed Apr  3 00:57:03 2002
@@ -63,7 +63,7 @@
 #include <osl/diagnose.h>
 #include <osl/process.h>
 
-#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD) || defined(FREEBSD)
 #include <pthread.h>
 #include <locale.h>
 #include <langinfo.h>
@@ -242,7 +242,7 @@
     return NULL;
 }
         
-#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD) || defined(FREEBSD)
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -314,7 +314,7 @@
    { "sjis",		RTL_TEXTENCODING_SHIFT_JIS	}, /* Japan */
 };
 
-#elif defined(LINUX) || defined(NETBSD)
+#elif defined(LINUX) || defined(NETBSD) || defined(FREEBSD)
 
 const _pair _nl_language_list[] = {
     { "ANSI_X3.110-1983",           RTL_TEXTENCODING_DONTKNOW   },  /* ISO-IR-99 NAPLPS */
@@ -495,7 +495,7 @@
     { "WIN-SAMI-2",                 RTL_TEXTENCODING_DONTKNOW }     /* WS2 */
 };
 
-#endif /* ifdef LINUX || NETBSD */
+#endif /* ifdef LINUX || NETBSD || FREEBSD */
 
 static pthread_mutex_t aLocalMutex = PTHREAD_MUTEX_INITIALIZER;
 
@@ -617,7 +617,7 @@
     return ret;
 }
 
-#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD */
+#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD || FREEBSD */
 
 /*
  * FIXME: the MacOS X implemetation is missing
@@ -650,7 +650,7 @@
     return 0;
 }
 
-#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -884,6 +884,6 @@
     return 0;
 }
 
-#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 
