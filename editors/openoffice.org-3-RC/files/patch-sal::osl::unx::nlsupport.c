--- ../sal/osl/unx/nlsupport.c.orig	Mon Nov 12 21:21:31 2001
+++ ../sal/osl/unx/nlsupport.c
@@ -63,7 +63,7 @@
 #include <osl/diagnose.h>
 #include <osl/process.h>
 
-#if defined(LINUX) || defined(SOLARIS)
+#if defined(LINUX) || defined(SOLARIS) || defined(NETBSD) || defined(FREEBSD)
 #include <pthread.h>
 #include <locale.h>
 #include <langinfo.h>
@@ -242,7 +242,7 @@
     return NULL;
 }
         
-#if defined(LINUX) || defined(SOLARIS)
+#if defined(LINUX) || defined(SOLARIS) || defined(NETBSD) || defined(FREEBSD)
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -296,7 +296,7 @@
 /* XXX MS-874 is an extension to tis620, so this is not
  * really equivalent */
 
-#elif defined(LINUX)
+#elif defined(LINUX) || defined(NETBSD) || defined(FREEBSD)
 
 const _pair _nl_language_list[] = {
     { "ANSI_X3.110-1983",           RTL_TEXTENCODING_DONTKNOW   },  /* ISO-IR-99 NAPLPS */
@@ -477,7 +477,7 @@
     { "WIN-SAMI-2",                 RTL_TEXTENCODING_DONTKNOW }     /* WS2 */
 };
 
-#endif /* ifdef LINUX */
+#endif /* ifdef LINUX || NETBSD || FREEBSD */
 
 static pthread_mutex_t aLocalMutex = PTHREAD_MUTEX_INITIALIZER;
 
@@ -516,7 +516,13 @@
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
@@ -595,7 +599,7 @@
     return ret;
 }
 
-#elif defined(MACOSX) /* ifdef LINUX || SOLARIS */
+#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD || FREEBSD */
 
 /*
  * FIXME: the MacOS X implemetation is missing
@@ -628,7 +632,7 @@
     return 0;
 }
 
-#else /* ifdef LINUX || SOLARIS || MACOSX */
+#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -829,7 +833,7 @@
             snprintf(env_buf, sizeof(env_buf), "LC_ALL=%s", locale_buf);
             env_buf[sizeof(env_buf)] = '\0';
             putenv(env_buf);
-#elif defined( FREEBSD ) || defined( NETBSD )
+#elif defined( FREEBSD ) 
             setenv( "LC_ALL", locale_buf, 1);
 #else
             setenv( "LC_ALL", locale_buf );
@@ -841,7 +845,7 @@
             snprintf(env_buf, sizeof(env_buf), "LC_CTYPE=%s", locale_buf);
             env_buf[sizeof(env_buf)] = '\0';
             putenv(env_buf);
-#elif defined( FREEBAD ) || defined( NETBSD )
+#elif defined( FREEBSD ) 
             setenv("LC_CTYPE", locale_buf, 1 );
 #else
             setenv( "LC_CTYPE", locale_buf );
@@ -853,7 +857,7 @@
             snprintf(env_buf, sizeof(env_buf), "LANG=%s", locale_buf);
             env_buf[sizeof(env_buf)] = '\0';
             putenv(env_buf);
-#elif defined( FREEBAD ) || defined( NETBSD )
+#elif defined( FREEBSD ) 
             setenv("LC_CTYPE", locale_buf, 1 );
 #else
             setenv( "LANG", locale_buf );
@@ -864,6 +868,6 @@
     return 0;
 }
 
-#endif /* ifdef LINUX || SOLARIS || MACOSX*/
+#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 
