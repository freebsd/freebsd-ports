--- includes/KeyboardKey.h.orig	2008-03-18 17:51:54.744835728 +0100
+++ includes/KeyboardKey.h	2008-03-18 17:52:13.290787518 +0100
@@ -38,7 +38,7 @@
   /**
    * Constructor
    */
-  KeyboardKey::KeyboardKey(int key, bool repeat = false)
+  KeyboardKey(int key, bool repeat = false)
   {
     this->key = key;
     this->repeat = repeat;
