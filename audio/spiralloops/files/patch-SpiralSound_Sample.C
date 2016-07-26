--- SpiralSound/Sample.C.orig	Wed Nov 22 13:02:12 2006
+++ SpiralSound/Sample.C	Wed Nov 22 13:03:58 2006
@@ -18,9 +18,9 @@
 
 #include <string.h>
 #include "Sample.h"
-#include "iostream.h"
+#include "iostream"
 
-Sample::Sample(int Len=0) :
+Sample::Sample(int Len) :
 m_Data(NULL),
 m_Length(0)
 {
