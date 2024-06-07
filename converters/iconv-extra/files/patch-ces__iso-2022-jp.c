--- ces/iso-2022-jp.c.orig	2000-11-20 22:34:57 UTC
+++ ces/iso-2022-jp.c
@@ -31,7 +31,7 @@
  */
 
 #define ICONV_INTERNAL
-#include <iconv.h>
+#include <biconv.h>
 
 static const iconv_ces_iso2022_ccs ccsattr[] = {
 	{"us-ascii",		"\x1b(B", 3, ICONV_SHIFT_SI},
