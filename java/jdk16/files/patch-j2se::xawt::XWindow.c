$FreeBSD$

--- ../../j2se/src/solaris/native/sun/xawt/XWindow.c	8 Nov 2004 22:27:40 -0000	1.1.1.1
+++ ../../j2se/src/solaris/native/sun/xawt/XWindow.c	19 Apr 2006 22:21:51 -0000
@@ -204,10 +204,10 @@
     {java_awt_event_KeyEvent_VK_DOWN, XK_Down, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_STANDARD},
 
     /* Keypad equivalents of Triangular Navigation Block */
-    {java_awt_event_KeyEvent_VK_KP_LEFT, XK_KP_Left, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
-    {java_awt_event_KeyEvent_VK_KP_UP, XK_KP_Up, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
-    {java_awt_event_KeyEvent_VK_KP_RIGHT, XK_KP_Right, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
-    {java_awt_event_KeyEvent_VK_KP_DOWN, XK_KP_Down, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
+    {java_awt_event_KeyEvent_VK_LEFT, XK_KP_Left, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
+    {java_awt_event_KeyEvent_VK_UP, XK_KP_Up, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
+    {java_awt_event_KeyEvent_VK_RIGHT, XK_KP_Right, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
+    {java_awt_event_KeyEvent_VK_DOWN, XK_KP_Down, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_NUMPAD},
 
     /* Other vendor-specific Triangular Navigation Block */
     {java_awt_event_KeyEvent_VK_LEFT, osfXK_Left, FALSE, java_awt_event_KeyEvent_KEY_LOCATION_STANDARD},
@@ -742,7 +742,7 @@
 {
     KeySym originalKeysym = *keysym;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(_ALLBSD_SOURCE)
     /* The following code on Linux will cause the keypad keys
      * not to echo on JTextField when the NumLock is on. The
      * keysyms will be 0, because the last parameter 2 is not defined.
