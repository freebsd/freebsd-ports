--- java/src/charvax/swing/ButtonGroup.java.orig	Sat Dec 17 15:27:30 2005
+++ java/src/charvax/swing/ButtonGroup.java	Mon Jan 29 09:39:30 2007
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
