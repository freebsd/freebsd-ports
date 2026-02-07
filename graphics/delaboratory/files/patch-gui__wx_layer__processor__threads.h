--- gui_wx/layer_processor_threads.h.orig	2012-06-08 22:38:01 UTC
+++ gui_wx/layer_processor_threads.h
@@ -31,7 +31,7 @@ class wxThread;
 #include <map>
 #include "size.h"
 #include "renderer.h"
-#include "semaphore.h"
+#include "desemaphore.h"
 #include "base_layer.h"
 
 
