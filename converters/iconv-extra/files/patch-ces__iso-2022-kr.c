--- ces/iso-2022-kr.c.orig	2000-11-20 22:37:35 UTC
+++ ces/iso-2022-kr.c
@@ -31,7 +31,7 @@
  */
 
 #define ICONV_INTERNAL
-#include <iconv.h>
+#include <biconv.h>
 
 static const iconv_ces_iso2022_ccs ccsattr[] = {
 	{"us-ascii",	"",        0, ICONV_SHIFT_SI},
