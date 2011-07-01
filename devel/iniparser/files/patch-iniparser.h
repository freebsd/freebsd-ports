--- src/iniparser.h.orig	2011-03-29 22:36:06.000000000 +0800
+++ src/iniparser.h	2011-07-01 17:36:39.000000000 +0800
@@ -34,6 +34,10 @@
 
 #include "dictionary.h"
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 /*-------------------------------------------------------------------------*/
 /**
   @brief    Get number of sections in a dictionary
@@ -270,4 +274,8 @@
 /*--------------------------------------------------------------------------*/
 void iniparser_freedict(dictionary * d);
 
+#ifdef __cplusplus
+}
+#endif
+
 #endif
