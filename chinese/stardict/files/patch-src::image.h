--- src/image.h.orig	Sun Dec 15 00:37:41 2002
+++ src/image.h	Sun Dec 15 00:37:45 2002
@@ -17,7 +17,8 @@
 #ifndef IMAGE_H
 #define IMAGE_H
 
-#include <stdiostream.h>
+#include <iostream>
+using namespace std;
 #include <stdlib.h>
 #include <memory.h>
 #include <string.h>
