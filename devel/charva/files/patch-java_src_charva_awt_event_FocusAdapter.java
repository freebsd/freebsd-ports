--- java/src/charva/awt/event/FocusAdapter.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charva/awt/event/FocusAdapter.java
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
