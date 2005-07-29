--- sysui/tools/lngconv/lngconv.cxx.orig	Sat Jul 20 23:14:29 2002
+++ sysui/tools/lngconv/lngconv.cxx	Sat Jul 20 23:14:34 2002
@@ -62,7 +62,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 
-#if defined( LINUX ) || defined (SOLARIS) || defined(IRIX)
+#if defined(LINUX) || defined (SOLARIS) || defined(IRIX) || defined (FREEBSD)
 #include <locale.h>
 #include <langinfo.h>
 #endif
@@ -143,6 +143,7 @@
     { "iso8859-8",    RTL_TEXTENCODING_ISO_8859_8  },
     { "iso8859-9",    RTL_TEXTENCODING_ISO_8859_9  },
     { "koi8-r",       RTL_TEXTENCODING_KOI8_R      },
+    { "koi8-u",       RTL_TEXTENCODING_KOI8_U      },
     { "pck",          RTL_TEXTENCODING_MS_932      },
 #if (0)
     { "sun_eu_greek", RTL_TEXTENCODING_DONTKNOW    },
