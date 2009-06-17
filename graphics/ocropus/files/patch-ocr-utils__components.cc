--- ./ocr-utils/components.cc.orig	2009-06-01 05:18:41.000000000 +0900
+++ ./ocr-utils/components.cc	2009-06-17 19:44:58.000000000 +0900
@@ -26,6 +26,7 @@
 #include "colib/colib.h"
 #include "iulib/iulib.h"
 #include "components.h"
+extern char **environ;
 
 using namespace colib;
 
