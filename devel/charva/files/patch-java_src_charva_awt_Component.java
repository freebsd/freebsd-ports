--- java/src/charva/awt/Component.java.orig	Mon Aug 14 18:03:14 2006
+++ java/src/charva/awt/Component.java	Mon Jan 29 09:39:30 2007
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
