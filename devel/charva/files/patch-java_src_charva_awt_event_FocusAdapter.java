--- java/src/charva/awt/event/FocusAdapter.java.orig	Mon Jan 29 09:39:30 2007
+++ java/src/charva/awt/event/FocusAdapter.java	Mon Jan 29 09:39:30 2007
@@ -0,0 +1,17 @@
+package charva.awt.event;
+
+/**
+ * An abstract class for receiving key events. The methods provided in this
+ * class are empty; the class is provided as a convenience for implementing
+ * the KeyListener interface. You only have to implement the methods you
+ * are interested in.
+ */
+public abstract class FocusAdapter implements FocusListener {
+
+    public void focusGained(FocusEvent fe) {
+    }
+
+    public void focusLost(FocusEvent fe) {
+    }
+
+}
