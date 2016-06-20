--- java/src/charva/awt/Component.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charva/awt/Component.java
@@ -118,6 +118,17 @@ public abstract class Component {
     }
 
     /**
+     * Determines whether this component will be displayed on the screen
+     * if it's displayable.
+     * @return <code>true</code> if the component and all of its ancestors
+     *          are visible, <code>false</code> otherwise
+     */
+    public boolean isRecursivelyVisible() {
+	Container parent = getParent();
+        return _visible && (parent == null || parent.isRecursivelyVisible());
+    }
+
+    /**
      * To be implemented by concrete subclasses.
      */
     public abstract void draw();
@@ -449,7 +460,7 @@ public abstract class Component {
      * traversal.
      */
     public boolean isFocusTraversable() {
-        return (_enabled && _visible);
+        return (_enabled && isRecursivelyVisible());
     }
 
     /**
