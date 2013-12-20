--- main.cpp.orig	2009-03-14 01:46:04.000000000 +0300
+++ main.cpp	2013-12-21 03:29:52.401817465 +0400
@@ -26,6 +26,7 @@
 #include <fstream>
 #include <iostream>
 #include <sstream>
+#include <unistd.h> // for usleep()
 
 #include <sys/time.h>
 
@@ -340,6 +341,7 @@
       }
     }
   }
+  return false;
 }
 
 void classBullets::shoot(entity owner, gPs velocity)
