--- java/src/charvax/swing/ButtonGroup.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charvax/swing/ButtonGroup.java
@@ -63,9 +63,10 @@ public class ButtonGroup
      * Adds the specified button to the group.
      */
     public void add(AbstractButton button_) {
+        if (getSelection() != null)
+            button_.setSelected(false);
         _buttons.add(button_);
         button_.addItemListener(this);
-        button_.setSelected(false);
     }
 
     /**
@@ -133,10 +134,9 @@ public class ButtonGroup
         for (Enumeration e = _buttons.elements(); e.hasMoreElements();) {
 
             AbstractButton b = (AbstractButton) e.nextElement();
-            if (source != b || statechange != ItemEvent.SELECTED) {
+            if (source != b && statechange == ItemEvent.SELECTED) {
                 if (b.isSelected()) {
                     b._selected = false;
-                    b.setEnabled(true);
                 }
             }
         }
