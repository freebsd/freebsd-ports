--- src/ime.cpp.orig	2019-04-09 08:15:56 UTC
+++ src/ime.cpp
@@ -2,6 +2,7 @@
 #define Uses_SCIM_ICONV
 #define Uses_SCIM_CONFIG_BASE
 #define Uses_SCIM_CONFIG_PATH
+#include <cstring>
 #include <ctype.h>
 
 #include <scim.h>
