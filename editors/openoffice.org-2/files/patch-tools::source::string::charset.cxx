--- ../tools/source/string/charset.cxx.orig	Sun Mar 10 23:55:47 2002
+++ ../tools/source/string/charset.cxx	Mon Mar 11 00:00:56 2002
@@ -64,12 +64,14 @@
 #elif defined( OS2 )
 #define INCL_DOSNLS
 #include <svpm.h>
-#elif defined(LINUX) || defined(SOLARIS)
+#elif defined(LINUX) || defined(SOLARIS) || defined(FREEBSD)
 #include <stdio.h>
 #include <stdlib.h>
 #include <strings.h>
 #include <locale.h>
+#if !defined(FREEBSD) || OSVERSION > 500000
 #include <langinfo.h>
+#endif
 #ifndef _TOOLS_LANG_HXX
 #include <lang.hxx>
 #endif
@@ -126,7 +128,7 @@
 
 // -----------------------------------------------------------------------
 
-#if defined(NETBSD) || defined(SCO)
+#if defined(NETBSD) || defined(SCO) || defined(FREEBSD)
 
 // check if there is a charset qualifier at the end of the given locale string
 // e.g. de.ISO8859-15 or de.ISO8859-15@euro which strongly indicates what
@@ -707,7 +709,7 @@
 #ifdef UNX
         CharSet nTextEncoding;
 
-#if defined(NETBSD) || defined(SCO)
+#if defined(NETBSD) || defined(SCO) || defined(FREEBSD)
         nTextEncoding = GetSystemCharSetFromEnvironment();
         if (nTextEncoding == RTL_TEXTENCODING_DONTKNOW)
             nTextEncoding = GetSystemCharSetFromSystemLanguage();
