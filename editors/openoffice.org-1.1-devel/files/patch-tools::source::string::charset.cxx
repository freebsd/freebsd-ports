--- ../tools/source/string/charset.cxx.orig	Sun Mar 10 23:55:47 2002
+++ ../tools/source/string/charset.cxx	Sun Mar 10 23:57:30 2002
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
+if !defined(FREEBSD) || OSVERSION > 500000
 #include <langinfo.h>
+#endif
 #ifndef _TOOLS_LANG_HXX
 #include <lang.hxx>
 #endif
