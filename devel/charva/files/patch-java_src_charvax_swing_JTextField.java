--- java/src/charvax/swing/JTextField.java.orig	Fri Dec 30 16:15:12 2005
+++ java/src/charvax/swing/JTextField.java	Mon Jan 29 09:39:30 2007
@@ -118,11 +118,6 @@ public class JTextField
         return _columns;
     }
 
-    public void setFont(Font font_) {
-        _bold = ((font_.getStyle() & Font.BOLD) != 0);
-    }
-
-
     /**
      * Set the action command
      */
@@ -189,9 +184,8 @@ public class JTextField
          * UNDERLINE attribute.
          */
         int attrib = 0;
-        if (super._enabled)
+        if (_enabled)
             attrib |= Toolkit.A_UNDERLINE;
-
         if (_bold)
             attrib |= Toolkit.A_BOLD;
 
@@ -247,7 +241,7 @@ public class JTextField
 
         /*
          */
-        if (ke_.isActionKey() == false) {
+        if (!ke_.isActionKey() && (ke_.getID() == KeyEvent.KEY_TYPED)) {
 
             /* If it is a control character, ignore it.
              * @todo Do something more useful with control chars.
@@ -414,8 +408,6 @@ public class JTextField
 
     //====================================================================
     // INSTANCE VARIABLES
-
-    protected boolean _bold = false;
 
     protected int _columns;
 
