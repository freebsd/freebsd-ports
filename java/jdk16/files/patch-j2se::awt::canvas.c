$FreeBSD$

--- ../../j2se/src/solaris/native/sun/awt/canvas.c	10 Jan 2005 15:09:40 -0000	1.2
+++ ../../j2se/src/solaris/native/sun/awt/canvas.c	19 Apr 2006 22:21:51 -0000
@@ -258,10 +258,10 @@
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
@@ -1349,7 +1349,7 @@
 {
     KeySym originalKeysym = *keysym;
 
-#if !defined(__linux__) 	// XXXBSD: applies to FreeBSD?
+#if !defined(__linux__) && !defined(_ALLBSD_SOURCE)
     /* The following code on Linux will cause the keypad keys
      * not to echo on JTextField when the NumLock is on. The
      * keysyms will be 0, because the last parameter 2 is not defined.
Index: j2se/src/solaris/native/sun/xawt/XWindow.c
===================================================================
RCS file: /home/Java/CVS/JDK2/javasrc_1_5_scsl/j2se/src/solaris/native/sun/xawt/XWindow.c,v
retrieving revision 1.1.1.1
