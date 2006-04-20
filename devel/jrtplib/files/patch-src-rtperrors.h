--- src/rtperrors.h	Tue Feb 21 17:31:13 2006
+++ src/rtperrors.h	Sun Apr 16 20:46:09 2006
@@ -34,6 +34,7 @@
 
 #define RTPERRORS_H
 
+#include <stdio.h>
 #include <string>
 
 std::string RTPGetErrorString(int errcode);
