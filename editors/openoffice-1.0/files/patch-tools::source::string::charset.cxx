--- ../tools/source/string/charset.cxx.orig	Fri May 31 00:17:15 2002
+++ ../tools/source/string/charset.cxx	Fri May 31 00:17:17 2002
@@ -68,6 +68,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <strings.h>
+#if defined(FREEBSD)
+#include <string.h>
+#endif
 #include <locale.h>
 #include <langinfo.h>
 #ifndef _TOOLS_LANG_HXX
