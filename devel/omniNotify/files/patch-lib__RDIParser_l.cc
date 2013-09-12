--- ./lib/RDIParser_l.cc.orig	2003-10-23 06:39:12.000000000 +0200
+++ ./lib/RDIParser_l.cc	2013-09-12 19:37:04.939058703 +0200
@@ -53,7 +53,8 @@
 #ifdef __cplusplus
 
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 /* Use prototypes in function declarations. */
 #define YY_USE_PROTOS
