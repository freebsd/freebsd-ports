--- ../sal/osl/unx/nlsupport.c.orig	Tue May 21 15:22:11 2002
+++ ../sal/osl/unx/nlsupport.c	Wed Jul 31 10:28:29 2002
@@ -63,7 +63,7 @@
 #include <osl/diagnose.h>
 #include <osl/process.h>
 
-#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD) || defined(FREEBSD)
 #include <pthread.h>
 #include <locale.h>
 #include <langinfo.h>
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
+#if defined(LINUX) || defined(SOLARIS) || defined(IRIX) || defined(NETBSD) || defined(FREEBSD)
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
  * from nl_langinfo(CODESET) to rtl_textencoding defines. 
- * nl_langinfo() is supported only on Linux, Solaris and IRIX. 
+ * nl_langinfo() is supported only on Linux, Solaris and IRIX
+ * and FreeBSD. 
  *
  * This routine is SLOW because of the setlocale call, so
  * grab the result and cache it.
@@ -312,7 +312,30 @@
    { "big5",		RTL_TEXTENCODING_BIG5		}, /* China - Traditional Chinese */
    { "eucgbk",		RTL_TEXTENCODING_DONTKNOW	}, /* China - Simplified Chinese */
    { "gbk",		RTL_TEXTENCODING_GBK		}, /* China - Simplified Chinese */
-   { "sjis",		RTL_TEXTENCODING_SHIFT_JIS	}, /* Japan */
+   { "sjis",		RTL_TEXTENCODING_SHIFT_JIS	}  /* Japan */
+};
+
+#elif defined(FREEBSD)
+
+const _pair _nl_language_list[] = {
+   { "US-ASCII",	RTL_TEXTENCODING_ASCII_US	}, /* US-ASCII */
+   { "ASCII",		RTL_TEXTENCODING_ASCII_US	}, /* US-ASCII */
+   { "ISO8859-1",	RTL_TEXTENCODING_ISO_8859_1	}, /* Western */
+   { "ISO8859-2",	RTL_TEXTENCODING_ISO_8859_2	}, /* Central European */
+   { "ISO8859-4",	RTL_TEXTENCODING_ISO_8859_4	}, /* LATIN4 L4 */
+   { "ISO8859-5",	RTL_TEXTENCODING_ISO_8859_5	}, /* Cyrillic */
+   { "ISO8859-7",	RTL_TEXTENCODING_ISO_8859_7	}, /* Greek */
+   { "ISO8859-9",	RTL_TEXTENCODING_ISO_8859_9	}, /* Turkish */
+   { "ISO8859-15",	RTL_TEXTENCODING_ISO_8859_15	}, /* Western Updated (w/Euro sign) */
+   { "KOI8-R",		RTL_TEXTENCODING_KOI8_R		},
+   { "KOI8-U",		RTL_TEXTENCODING_DONTKNOW	},
+   { "CP866",		RTL_TEXTENCODING_IBM_866	}, /* CP866 866 */
+   { "CP1251",		RTL_TEXTENCODING_MS_1251	}, /* MS-CYRL */
+   { "eucJP",		RTL_TEXTENCODING_EUC_JP		}, /* Japan */
+   { "eucKR",		RTL_TEXTENCODING_EUC_KR		}, /* Korea */
+   { "eucCN",		RTL_TEXTENCODING_EUC_CN		}, /* China */
+   { "big5",		RTL_TEXTENCODING_BIG5		}, /* China - Traditional Chinese */
+   { "sjis",		RTL_TEXTENCODING_SHIFT_JIS	}  /* Japan */
 };
 
 #elif defined(LINUX) || defined(NETBSD)
@@ -496,7 +519,7 @@
     { "WIN-SAMI-2",                 RTL_TEXTENCODING_DONTKNOW }     /* WS2 */
 };
 
-#endif /* ifdef LINUX || NETBSD */
+#endif /* ifdef LINUX || NETBSD || FREEBSD */
 
 static pthread_mutex_t aLocalMutex = PTHREAD_MUTEX_INITIALIZER;
 
@@ -618,7 +641,7 @@
     return ret;
 }
 
-#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD */
+#elif defined(MACOSX) /* ifdef LINUX || SOLARIS || NETBSD || FREEBSD */
 
 /*
  * FIXME: the MacOS X implemetation is missing
@@ -651,7 +674,7 @@
     return 0;
 }
 
-#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#else /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 /*
  * This implementation of osl_getTextEncodingFromLocale maps 
@@ -887,6 +910,6 @@
     return 0;
 }
 
-#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD */
+#endif /* ifdef LINUX || SOLARIS || MACOSX || NETBSD || FREEBSD */
 
 
