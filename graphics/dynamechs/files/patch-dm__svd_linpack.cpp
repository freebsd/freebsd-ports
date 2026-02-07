--- dm/svd_linpack.cpp.orig
+++ dm/svd_linpack.cpp
@@ -10,7 +10,9 @@
 #endif
 
 #include <stdio.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
+using namespace std;
 
 #ifdef __cplusplus
 extern "C" {
