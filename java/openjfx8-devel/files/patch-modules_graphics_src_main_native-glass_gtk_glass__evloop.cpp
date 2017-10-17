--- modules/graphics/src/main/native-glass/gtk/glass_evloop.cpp.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/native-glass/gtk/glass_evloop.cpp
@@ -25,7 +25,8 @@
 #include "glass_evloop.h"
 
 #include <glib.h>
-#include <malloc.h>
+#include <sys/param.h>
+#include <stdlib.h>
 
 static GSList * evloopHookList;
 
@@ -85,4 +86,3 @@ glass_evloop_hook_remove(GevlHookRegistration hookReg)
     evloopHookList = g_slist_remove(evloopHookList, hookReg);
     free(hookReg);
 }
-
