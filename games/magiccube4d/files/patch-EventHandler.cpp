diff --git EventHandler.cpp EventHandler.cpp
index 398fcb7..f5fe00a 100644
--- EventHandler.cpp
+++ EventHandler.cpp
@@ -31,6 +31,9 @@ DESCRIPTION:
 #include "MacroManager.h"
 #include "PostScriptWriter.h"
 
+#include <stdint.h>
+static intptr_t ptr2int(const void* p) { return reinterpret_cast<intptr_t>(p); }
+
 float const EventHandler::DEF_TWIST_INCREMENT = 0.5;
 
 EventHandler::EventHandler(int argc, char **argv, char const* machine_type) :
@@ -326,7 +329,7 @@ EventHandler::getAReferenceSticker(Event *event, void *)
         number_of_reference_stickers_needed--;
         reference_stickers_needed++;
         if (number_of_reference_stickers_needed == 0)
-            (this->*what_to_do_after_got_reference_stickers)();
+            (this->*what_to_do_after_got_reference_stickers)(NULL);
     }
 }
 
@@ -415,7 +418,7 @@ EventHandler::buttonDown_handler(Event *event, void *arg)
 void
 EventHandler::undo_cb(void* argp)
 {
-    int arg = (int) argp;
+    int arg = ptr2int(argp);
     struct stickerspec grip;
     int         dir;
     int         slicesmask;
@@ -461,7 +464,7 @@ EventHandler::undo_cb(void* argp)
 void
 EventHandler::redo_cb(void* argp)
 {
-    int arg = (int) argp;
+    int arg = ptr2int(argp);
     struct stickerspec grip;
     int         dir;
     int         slicesmask;
@@ -507,7 +510,7 @@ EventHandler::redo_cb(void* argp)
 void
 EventHandler::scramble_cb(void *arg = NULL)
 {
-    int n = (int)arg;
+    int n = ptr2int(arg);
     struct stickerspec grip;
     int i, previous_face = -1;
     int ngrips = NFACES * 3 * 3 * 3;
@@ -855,12 +858,12 @@ EventHandler::toggleFast_cb(void *)
 void
 EventHandler::newPuzzle_cb(void* arg)
 {
-    if ((int)arg == preferences.getLength())
+    if (ptr2int(arg) == preferences.getLength())
     {
         reset_cb(0);
         return;
     }
-    preferences.setLength((int)arg);
+    preferences.setLength(ptr2int(arg));
     int length = preferences.getLength();
 
     polymgr->reset(length);
