--- java/src/charvax/swing/ButtonGroup.java.orig	2005-12-17 15:27:30.000000000 +0100
+++ java/src/charvax/swing/ButtonGroup.java	2009-11-16 10:26:42.000000000 +0100
@@ -63,9 +63,10 @@
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
@@ -133,10 +134,9 @@
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
