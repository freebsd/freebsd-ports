--- src/LocaleRes.cpp.orig	2023-09-22 01:27:50 UTC
+++ src/LocaleRes.cpp
@@ -22,9 +22,9 @@
 //Description : Locale Resources
 
 #include <stdlib.h>
+#include <locale.h>
 #ifdef ENABLE_NLS
 #include <libintl.h>
-#include <locale.h>
 #endif
 
 #include <ALL.h>
