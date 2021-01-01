--- node_modules/atom-keymap/lib/helpers.js.orig	1985-10-26 08:15:00 UTC
+++ node_modules/atom-keymap/lib/helpers.js
@@ -218,7 +218,7 @@
     if (KEY_NAMES_BY_KEYBOARD_EVENT_CODE[code] != null) {
       key = KEY_NAMES_BY_KEYBOARD_EVENT_CODE[code];
     }
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       if (code === 'NumpadDecimal' && !event.getModifierState('NumLock')) {
         key = 'delete';
       }
@@ -257,7 +257,7 @@
             altKey = false;
             isAltModifiedKey = true;
           }
-        } else if (process.platform === 'linux') {
+        } else if (process.platform === 'linux' || process.platform === 'freebsd') {
           nonAltModifiedKey = nonAltModifiedKeyForKeyboardEvent(event);
           if (nonAltModifiedKey && (ctrlKey || altKey || metaKey)) {
             key = nonAltModifiedKey;
