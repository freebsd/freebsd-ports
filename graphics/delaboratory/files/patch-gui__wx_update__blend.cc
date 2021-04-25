--- gui_wx/update_blend.cc.orig	2012-06-12 00:31:57 UTC
+++ gui_wx/update_blend.cc
@@ -20,7 +20,7 @@
 #include <wx/wx.h>
 #include "color_space_utils.h"
 #include "layer_with_blending.h"
-#include "semaphore.h"
+#include "desemaphore.h"
 
 class deUpdateBlendThread:public wxThread
 {
