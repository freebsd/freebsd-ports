--- tools/toolutil/pkg_gencmn.c.orig	2011-05-23 23:56:16.000000000 +0200
+++ tools/toolutil/pkg_gencmn.c	2011-06-21 12:19:03.995937644 +0200
@@ -18,7 +18,7 @@
 #include "putilimp.h"
 #include "pkg_gencmn.h"
 
-#define STRING_STORE_SIZE 100000
+#define STRING_STORE_SIZE 131072
 
 #define COMMON_DATA_NAME U_ICUDATA_NAME
 #define DATA_TYPE "dat"
