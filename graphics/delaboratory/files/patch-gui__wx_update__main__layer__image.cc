--- gui_wx/update_main_layer_image.cc.orig	2012-07-26 00:53:58 UTC
+++ gui_wx/update_main_layer_image.cc
@@ -19,7 +19,7 @@
 #include "update_main_layer_image.h"
 #include <wx/wx.h>
 #include "base_layer.h"
-#include "semaphore.h"
+#include "desemaphore.h"
 #include "logger.h"
 #include "color_space_utils.h"
 #include "str.h"
