--- ../svx/source/dialog/graphctl.cxx	2001/08/16 15:41:29	1.6
+++ ../svx/source/dialog/graphctl.cxx	2002/03/03 19:41:13
@@ -62,12 +62,12 @@
 #if defined( OS2 ) || defined( WIN ) || defined( UNX ) || defined( WNT )
 #include <stdlib.h>			//wegen fcvt
 #endif
-#if defined(MAC) || defined(NETBSD)
-#if defined(NETBSD)
+#if defined(MAC) || defined(NETBSD) || defined(FREEBSD)
+#if defined(NETBSD) || defined(FREEBSD)
 extern "C" {
 #endif
 char *fcvt(double value, int ndigit, int *decpt, int *sign);
-#if defined(NETBSD)
+#if defined(NETBSD) || defined(FREEBSD)
 }
 #endif
 #endif
