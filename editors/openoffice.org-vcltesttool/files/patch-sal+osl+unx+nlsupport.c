--- ../sal/osl/unx/nlsupport.c.orig	Tue May 21 15:22:11 2002
+++ ../sal/osl/unx/nlsupport.c	Wed Jul 31 10:28:29 2002
@@ -63,7 +63,7 @@
 #include <osl/diagnose.h>
 #include <osl/process.h>
 
-#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(FREEBSD)
 #include <pthread.h>
 #include <locale.h>
 #include <langinfo.h>
@@ -87,7 +87,7 @@
 static int
 _pair_compare (const char *key, const _pair *pair)
 {
-    int result = rtl_str_compareIgnoreAsciiCase( key, pair->key );
+    unsigned int result = rtl_str_compareIgnoreAsciiCase( key, pair->key );
     return result;
 }
 
@@ -114,8 +114,7 @@
         comparison = _pair_compare( key, base + current );
         if (comparison < 0)
             upper = current;
-        else
-        if (comparison > 0)
+        else if (comparison > 0)
             lower = current + 1;
         else
             return base + current;
@@ -241,12 +240,13 @@
     return NULL;
 }
         
-#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(FREEBSD)
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
  * from nl_langinfo(CODESET) to rtl_textencoding defines. 
- * nl_langinfo() is supported only on Linux, Solaris and IRIX. 
+ * nl_langinfo() is supported only on Linux, Solaris and IRIX
+ * and FreeBSD. 
  *
  * This routine is SLOW because of the setlocale call, so
  * grab the result and cache it.
@@ -260,6 +260,10 @@
 #endif
 #endif
 
+/*
+ * _nl_language_list[] is an array list of supported encodings. Because
+ * we are using a binary search, the list has to be in ascending order.
+ */
 
 #if defined(SOLARIS)
 
@@ -312,10 +316,33 @@
    { "big5",		RTL_TEXTENCODING_BIG5		}, /* China - Traditional Chinese */
    { "eucgbk",		RTL_TEXTENCODING_DONTKNOW	}, /* China - Simplified Chinese */
    { "gbk",		RTL_TEXTENCODING_GBK		}, /* China - Simplified Chinese */
+   { "sjis",		RTL_TEXTENCODING_SHIFT_JIS	}  /* Japan */
+};
+
+#elif defined(FREEBSD)
+
+const _pair _nl_language_list[] = {
+   { "ascii",		RTL_TEXTENCODING_ASCII_US	}, /* US-ASCII */
+   { "big5",		RTL_TEXTENCODING_BIG5		}, /* China - Traditional Chinese */
+   { "cp1251",		RTL_TEXTENCODING_MS_1251	}, /* MS-CYRL */
+   { "cp866",		RTL_TEXTENCODING_IBM_866	}, /* CP866 866 */
+   { "eucCN",		RTL_TEXTENCODING_EUC_CN		}, /* China - Simplified Chinese */
+   { "eucJP",		RTL_TEXTENCODING_EUC_JP		}, /* Japan */
+   { "eucKR",		RTL_TEXTENCODING_EUC_KR		}, /* Korea */
+   { "iso8859-1",	RTL_TEXTENCODING_ISO_8859_1	}, /* Western */
+   { "iso8859-15",	RTL_TEXTENCODING_ISO_8859_15	}, /* Western Updated (w/Euro sign) */
+   { "iso8859-2",	RTL_TEXTENCODING_ISO_8859_2	}, /* Central European */
+   { "iso8859-4",	RTL_TEXTENCODING_ISO_8859_4	}, /* LATIN4 L4 */
+   { "iso8859-5",	RTL_TEXTENCODING_ISO_8859_5	}, /* Cyrillic */
+   { "iso8859-7",	RTL_TEXTENCODING_ISO_8859_7	}, /* Greek */
+   { "iso8859-9",	RTL_TEXTENCODING_ISO_8859_9	}, /* Turkish */
+   { "koi-u",		RTL_TEXTENCODING_DONTKNOW	}, /* Not supported at the moment */
+   { "koi8-r",		RTL_TEXTENCODING_KOI8_R		}, /* KOI8 */
    { "sjis",		RTL_TEXTENCODING_SHIFT_JIS	}, /* Japan */
+   { "us-ascii",	RTL_TEXTENCODING_ASCII_US	}  /* US-ASCII */
 };
 
-#elif defined(LINUX) || defined(NETBSD)
+#elif defined(LINUX)
 
 const _pair _nl_language_list[] = {
     { "ANSI_X3.110-1983",           RTL_TEXTENCODING_DONTKNOW   },  /* ISO-IR-99 NAPLPS */
@@ -496,7 +523,7 @@
     { "WIN-SAMI-2",                 RTL_TEXTENCODING_DONTKNOW }     /* WS2 */
 };
 
-#endif /* ifdef LINUX || NETBSD */
+#endif /* ifdef LINUX || FREEBSD */
 
 static pthread_mutex_t aLocalMutex = PTHREAD_MUTEX_INITIALIZER;
 
@@ -618,7 +645,7 @@
     return ret;
 }
 
-#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD */
+#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || FREEBSD */
 
 /*
  * FIXME: the MacOS X implemetation is missing
@@ -651,7 +678,7 @@
     return 0;
 }
 
-#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#else /* ifdef LINUX || SOLARIS || FREEBSD || MACOSX */
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -887,6 +914,6 @@
     return 0;
 }
 
-#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#endif /* ifdef LINUX || SOLARIS || MACOSX || FREEBSD */
 
 
