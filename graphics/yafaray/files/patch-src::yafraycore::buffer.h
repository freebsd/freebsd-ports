--- src/yafraycore/buffer.h.orig	Thu Sep 30 14:31:34 2004
+++ src/yafraycore/buffer.h	Thu Sep 30 14:42:42 2004
@@ -27,7 +27,10 @@
 #include<config.h>
 #endif
 
+#include <iostream>
 #include <stdio.h>
+
+using namespace std;
 
 __BEGIN_YAFRAY
 
