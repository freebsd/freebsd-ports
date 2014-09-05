--- unix/fcitx/surrounding_text_util.cc.orig	2014-08-31 07:02:14.000000000 +0900
+++ unix/fcitx/surrounding_text_util.cc	2014-08-31 07:03:49.000000000 +0900
@@ -32,7 +32,9 @@
 #include <limits>
 #include <string>
 #include <fcitx/instance.h>
+#if 0
 #include <fcitx/module/clipboard/fcitx-clipboard.h>
+#endif
 
 #include "base/port.h"
 #include "base/logging.h"
@@ -207,6 +209,7 @@
     const string surrounding_text(str);
     free(str);
 
+#if 0
     if (cursor_pos == anchor_pos) {
         const char* primary = NULL;
 
@@ -220,6 +223,7 @@
             }
         }
     }
+#endif
 
     if (!SurroundingTextUtil::GetSafeDelta(cursor_pos, anchor_pos,
                                            &info->relative_selected_length)) {
