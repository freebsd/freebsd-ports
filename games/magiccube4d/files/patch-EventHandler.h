--- EventHandler.h.orig	Sat Dec 30 23:41:44 2006
+++ EventHandler.h	Sat Dec 30 23:42:05 2006
@@ -165,7 +165,7 @@
 
     int  number_of_reference_stickers_needed;
     int  (*reference_stickers_needed)[4];
-    void (EventHandler::*what_to_do_after_got_reference_stickers) (void *arg = NULL);
+    void (EventHandler::*what_to_do_after_got_reference_stickers) (void *arg);
     void* cur_ui_data;
 
     bool quick_mode;
