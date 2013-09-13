--- main.cpp.orig	2013-09-13 20:24:16.310226753 +0400
+++ main.cpp	2013-09-13 20:24:50.127352703 +0400
@@ -26,6 +26,7 @@
 #include <fstream>
 #include <iostream>
 #include <sstream>
+#include <unistd.h> // for usleep()
 
 #include <sys/time.h>
 
