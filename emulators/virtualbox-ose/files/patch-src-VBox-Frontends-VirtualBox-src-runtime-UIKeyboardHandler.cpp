--- src/VBox/Frontends/VirtualBox/src/runtime/UIKeyboardHandler.cpp.orig	2015-03-02 10:09:41.000000000 -0500
+++ src/VBox/Frontends/VirtualBox/src/runtime/UIKeyboardHandler.cpp	2015-03-12 17:11:33.029804000 -0400
@@ -622,7 +622,7 @@
             unsigned scan = handleXKeyEvent(pEvent);
 
             /* Scancodes 0x00 (no valid translation) and 0x80 are ignored: */
-            if (!scan & 0x7F)
+            if (!(scan & 0x7F))
             {
                 fResult = true;
                 break;
@@ -1603,7 +1603,7 @@
     {
         KeySym ks = wrapXkbKeycodeToKeysym(pDisplay, keyCode, i, 0);
         char symbol = 0;
-        if (!XkbTranslateKeySym(pDisplay, &ks, 0, &symbol, 1, NULL) == 1)
+        if (XkbTranslateKeySym(pDisplay, &ks, 0, &symbol, 1, NULL) == 0)
             symbol = 0;
         if (symbol)
         {
