--- ./src/AppWindow.cpp.orig	Sun Jun 10 01:55:15 2007
+++ ./src/AppWindow.cpp	Sun Jun 10 01:55:33 2007
@@ -24,6 +24,7 @@
 #include "../config.h"
 
 extern "C" {
+#include <libintl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
