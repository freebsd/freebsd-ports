--- eboxy/main.cpp.orig	Mon Sep 16 02:35:53 2002
+++ eboxy/main.cpp	Mon Sep 16 02:36:03 2002
@@ -19,6 +19,7 @@
 #include "config.h"
 #endif
 
+#define __GNU_LIBRARY__
 #include <ctype.h>
 #include <stdio.h>
 #include <iostream.h>
