--- modules/javafx.graphics/src/main/native-glass/gtk/glass_evloop.cpp.orig	2020-07-24 17:23:31 UTC
+++ modules/javafx.graphics/src/main/native-glass/gtk/glass_evloop.cpp
@@ -25,7 +25,7 @@
 #include "glass_evloop.h"
 
 #include <glib.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 static GSList * evloopHookList;
 
