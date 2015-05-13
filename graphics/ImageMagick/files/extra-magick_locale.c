--- magick/locale.c.orig	2015-04-14 23:09:38.000000000 +0200
+++ magick/locale.c	2015-04-27 12:00:08.997474000 +0200
@@ -66,6 +66,14 @@
 #define MaxRecursionDepth  200
 
 /*
+  Typedef declarations.
+*/
+#if defined(__CYGWIN__)
+typedef struct _locale_t
+  *locale_t;
+#endif
+
+/*
   Static declarations.
 */
 static const char
@@ -86,7 +94,7 @@ static SemaphoreInfo
 static SplayTreeInfo
   *locale_cache = (SplayTreeInfo *) NULL;
 
-#if defined(MAGICKCORE_HAVE_LOCALE_H)
+#if defined(MAGICKCORE_HAVE_STRTOD_L)
 static volatile locale_t
   c_locale = (locale_t) NULL;
 #endif
@@ -99,7 +107,7 @@ static MagickBooleanType
   LoadLocaleCache(SplayTreeInfo *,const char *,const char *,const char *,
     const size_t,ExceptionInfo *);
 
-#if defined(MAGICKCORE_HAVE_LOCALE_H)
+#if defined(MAGICKCORE_HAVE_STRTOD_L)
 /*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %                                                                             %
@@ -229,7 +237,7 @@ static SplayTreeInfo *AcquireLocaleSplay
   return(locale_cache);
 }
 
-#if defined(MAGICKCORE_HAVE_LOCALE_H)
+#if defined(MAGICKCORE_HAVE_STRTOD_L)
 /*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %                                                                             %
@@ -331,7 +339,7 @@ MagickExport ssize_t FormatLocaleFileLis
   ssize_t
     n;
 
-#if defined(MAGICKCORE_HAVE_LOCALE_H) && defined(MAGICKCORE_HAVE_VFPRINTF_L)
+#if defined(MAGICKCORE_HAVE_VFPRINTF_L)
   {
     locale_t
       locale;
@@ -347,7 +355,7 @@ MagickExport ssize_t FormatLocaleFileLis
 #endif
   }
 #else
-#if defined(MAGICKCORE_HAVE_LOCALE_H) && defined(MAGICKCORE_HAVE_USELOCALE)
+#if defined(MAGICKCORE_HAVE_USELOCALE) && defined(MAGICKCORE_HAVE_STRTOD_L)
   {
     locale_t
       locale,
@@ -422,7 +430,7 @@ MagickExport ssize_t FormatLocaleStringL
   ssize_t
     n;
 
-#if defined(MAGICKCORE_HAVE_LOCALE_H) && defined(MAGICKCORE_HAVE_VSNPRINTF_L)
+#if defined(MAGICKCORE_HAVE_VSNPRINTF_L)
   {
     locale_t
       locale;
@@ -438,7 +446,7 @@ MagickExport ssize_t FormatLocaleStringL
 #endif
   }
 #elif defined(MAGICKCORE_HAVE_VSNPRINTF)
-#if defined(MAGICKCORE_HAVE_LOCALE_H) && defined(MAGICKCORE_HAVE_USELOCALE)
+#if defined(MAGICKCORE_HAVE_USELOCALE) && defined(MAGICKCORE_HAVE_STRTOD_L)
   {
     locale_t
       locale,
@@ -981,7 +989,7 @@ MagickExport double InterpretLocaleValue
     value=(double) strtoul(string,&q,16);
   else
     {
-#if defined(MAGICKCORE_HAVE_LOCALE_H) && defined(MAGICKCORE_HAVE_STRTOD_L)
+#if defined(MAGICKCORE_HAVE_STRTOD_L)
       locale_t
         locale;
 
@@ -1420,7 +1428,7 @@ MagickExport void LocaleComponentTerminu
   LockSemaphoreInfo(locale_semaphore);
   if (locale_cache != (SplayTreeInfo *) NULL)
     locale_cache=DestroySplayTree(locale_cache);
-#if defined(MAGICKCORE_HAVE_LOCALE_H)
+#if defined(MAGICKCORE_HAVE_STRTOD_L)
   DestroyCLocale();
 #endif
   UnlockSemaphoreInfo(locale_semaphore);
