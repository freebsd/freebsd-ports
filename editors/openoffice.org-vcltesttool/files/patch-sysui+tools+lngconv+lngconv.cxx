--- ../sysui/tools/lngconv/lngconv.cxx.orig	Sat Jul 20 23:14:29 2002
+++ ../sysui/tools/lngconv/lngconv.cxx	Sat Jul 20 23:14:34 2002
@@ -62,7 +62,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 
-#if defined( LINUX ) || defined (SOLARIS)
+#if defined(LINUX) || defined (SOLARIS) || defined (FREEBSD)
 #include <locale.h>
 #include <langinfo.h>
 #endif
