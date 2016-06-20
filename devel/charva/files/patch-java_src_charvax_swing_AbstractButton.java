--- java/src/charvax/swing/AbstractButton.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charvax/swing/AbstractButton.java
@@ -19,15 +19,16 @@
 
 package charvax.swing;
 
+import java.util.Enumeration;
+import java.util.Vector;
+
+import charva.awt.Container;
 import charva.awt.EventQueue;
 import charva.awt.ItemSelectable;
 import charva.awt.Toolkit;
 import charva.awt.Window;
 import charva.awt.event.*;
 
-import java.util.Enumeration;
-import java.util.Vector;
-
 /**
  * This forms the base class for components that exhibit button-like
  * behavior.
@@ -50,6 +51,12 @@ public abstract class AbstractButton
         _label = label_;
     }
 
+    protected void addKeyListenerToAncestor() {
+        Window ancestor = super.getAncestorWindow();
+        if (ancestor != null)
+            ancestor.addKeyListener(this);
+    }
+
     /**
      * Set the button's mnemonic character.
      * The mnemonic is the key which will activate this button if focus
@@ -76,10 +83,16 @@ public abstract class AbstractButton
      */
     public void setMnemonic(int mnemonic_) {
         _mnemonic = mnemonic_;
-        Window ancestor = super.getAncestorWindow();
-        if (ancestor != null) {
-            ancestor.addKeyListener(this);
-        }
+        addKeyListenerToAncestor();
+    }
+
+    public void setParent(Container container_) {
+	if ((_mnemonic != 0) && (_parent != null) && (_parent.get() != null))
+	    throw new RuntimeException("Removal from previous parent currently not implemented");
+	    //removeKeyListenerFromAncestor();
+	super.setParent(container_);
+	if (_mnemonic != 0)
+	    addKeyListenerToAncestor();
     }
 
     /**
@@ -237,24 +250,23 @@ public abstract class AbstractButton
      * character or a function key or cursor key was typed.
      */
     public void keyPressed(KeyEvent ke_) {
-        if (ke_.getKeyCode() == getMnemonic()) {
+	int code = ke_.getKeyCode();
+	int mnem = getMnemonic();
+	if (!ke_.isActionKey()) {
+	    code = Character.toLowerCase(code);
+	    mnem = Character.toLowerCase(mnem);
+	}
+        if (code == mnem) {
             doClick();
             ke_.consume();
         }
     }
 
     /**
-     * Implements the KeyListener interface; this is called if a printable
-     * (ASCII or ISO8859-1) character was typed.
+     * Implements the KeyListener interface; this is called only if a
+     * printable (ASCII or ISO8859-1) character was typed.
      */
     public void keyTyped(KeyEvent ke_) {
-        // We must accept either uppercase or lowercase mnemonic characters.
-        char keyLower = Character.toLowerCase((char) ke_.getKeyChar());
-        char mnemonicLower = Character.toLowerCase((char) getMnemonic());
-        if (keyLower == mnemonicLower) {
-            doClick();
-            ke_.consume();
-        }
     }
 
     /**
