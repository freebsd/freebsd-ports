--- objdump/bool.cc.orig	1995-06-24 08:37:24.000000000 +0400
+++ objdump/bool.cc	2013-10-09 13:50:33.000000000 +0400
@@ -1,17 +1,17 @@
-#include <iostream.h>
+#include <iostream>
 
-main ()
+int main (void)
 {
   switch (sizeof (bool))
     {
       case 1:
-        cout << "typedef unsigned char bool;\n";
+        std::cout << "typedef unsigned char bool;\n";
 	break;
       case 2:
-        cout << "typedef unsigned short bool;\n";
+        std::cout << "typedef unsigned short bool;\n";
 	break;
       case 4:
-        cout << "typedef unsigned long bool;\n";
+        std::cout << "typedef unsigned long bool;\n";
 	break;
     }
 }
