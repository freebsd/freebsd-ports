--- java/src/charva/awt/Toolkit.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charva/awt/Toolkit.java
@@ -157,13 +157,9 @@ public class Toolkit {
      *             key as defined in the "VK_*" values.
      */
     public void fireKeystroke(int key_, Component source_) {
-        int id;
-        if (Toolkit.isActionKey(key_))
-            id = AWTEvent.KEY_TYPED;
-        else
-            id = AWTEvent.KEY_PRESSED;
-
-        _evtQueue.postEvent(new KeyEvent(key_, id, source_));
+	_evtQueue.postEvent(new KeyEvent(key_, AWTEvent.KEY_PRESSED, source_));
+	if (!Toolkit.isActionKey(key_))
+	    _evtQueue.postEvent(new KeyEvent(key_, AWTEvent.KEY_TYPED, source_));
     }
 
     public FocusEvent getLastFocusEvent() {
@@ -225,7 +221,7 @@ public class Toolkit {
             _lastMousePressTime = System.currentTimeMillis();
 
         Component component =
-                top_window.getComponentAt(x - origin.x, y - origin.y);
+                top_window.findComponentAt(x - origin.x, y - origin.y);
 
         if (component != null) {
             _evtQueue.postEvent(new MouseEvent(component, modifiers, x, y, 0, button));
@@ -796,43 +792,47 @@ public class Toolkit {
     //public boolean isActionKey() { return (_key >= 256); }
     public static boolean isActionKey( int _key )
     {
-        boolean value = false;
-        if ( _key == charva.awt.event.KeyEvent.VK_ESCAPE ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_DOWN ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_UP ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_LEFT ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_RIGHT ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_HOME ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_BACK_SPACE ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F1 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F2 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F3 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F4 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F5 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F6 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F7 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F8 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F9 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F10 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F11 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F12 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F13 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F14 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F15 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F16 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F17 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F18 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F19 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_F20 ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_DELETE ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_INSERT ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_PAGE_DOWN ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_PAGE_UP ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_ENTER ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_BACK_TAB ) value=true;
-        if ( _key == charva.awt.event.KeyEvent.VK_END ) value=true;
-
-        return (value);
+	switch (_key) {
+	case charva.awt.event.KeyEvent.VK_ESCAPE:
+	case charva.awt.event.KeyEvent.VK_DOWN:
+	case charva.awt.event.KeyEvent.VK_UP:
+	case charva.awt.event.KeyEvent.VK_LEFT:
+	case charva.awt.event.KeyEvent.VK_RIGHT:
+	case charva.awt.event.KeyEvent.VK_HOME:
+	case charva.awt.event.KeyEvent.VK_BACK_SPACE:
+	case charva.awt.event.KeyEvent.VK_F1:
+	case charva.awt.event.KeyEvent.VK_F2:
+	case charva.awt.event.KeyEvent.VK_F3:
+	case charva.awt.event.KeyEvent.VK_F4:
+	case charva.awt.event.KeyEvent.VK_F5:
+	case charva.awt.event.KeyEvent.VK_F6:
+	case charva.awt.event.KeyEvent.VK_F7:
+	case charva.awt.event.KeyEvent.VK_F8:
+	case charva.awt.event.KeyEvent.VK_F9:
+	case charva.awt.event.KeyEvent.VK_F10:
+	case charva.awt.event.KeyEvent.VK_F11:
+	case charva.awt.event.KeyEvent.VK_F12:
+	case charva.awt.event.KeyEvent.VK_F13:
+	case charva.awt.event.KeyEvent.VK_F14:
+	case charva.awt.event.KeyEvent.VK_F15:
+	case charva.awt.event.KeyEvent.VK_F16:
+	case charva.awt.event.KeyEvent.VK_F17:
+	case charva.awt.event.KeyEvent.VK_F18:
+	case charva.awt.event.KeyEvent.VK_F19:
+	case charva.awt.event.KeyEvent.VK_F20:
+	case charva.awt.event.KeyEvent.VK_DELETE:
+	case charva.awt.event.KeyEvent.VK_INSERT:
+	case charva.awt.event.KeyEvent.VK_PAGE_DOWN:
+	case charva.awt.event.KeyEvent.VK_PAGE_UP:
+	case charva.awt.event.KeyEvent.VK_ENTER:
+	case charva.awt.event.KeyEvent.VK_BACK_TAB:
+	case charva.awt.event.KeyEvent.VK_END:
+	    return true;
+	default:
+	    if ( _key < 32 )
+		return true;
+	    return false;
+	}
     }
 
     //====================================================================
