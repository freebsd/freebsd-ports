--- java/src/charva/awt/Container.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charva/awt/Container.java
@@ -89,6 +89,23 @@ public abstract class Container
         invalidate();
     }
 
+    public void setBounds(int top_, int left_, int bottom_, int right_) {
+	super.setBounds(top_, left_, bottom_, right_);
+	setSize(right_ - left_ + 1, bottom_ - top_ + 1);
+    }
+
+    public void setBounds(Point topleft_, Dimension size_) {
+	super.setBounds(topleft_, size_);
+	setSize(size_);
+    }
+
+    public void setBounds(Rectangle bounds) {
+	super.setBounds(bounds);
+	setSize(
+	    bounds.getRight() - bounds.getLeft() + 1,
+	    bounds.getBottom() - bounds.getTop() + 1);
+    }
+
     public Dimension minimumSize() {
         if (_layoutMgr == null)
             return _size;
@@ -105,13 +122,30 @@ public abstract class Container
         return (Component) _components.elementAt(n);
     }
 
+    protected Component getComponentAt(int x, int y, boolean checkVisibility) {
+        Enumeration e = _components.elements();
+        while (e.hasMoreElements()) {
+            Component c = (Component) e.nextElement();
+            if ((!checkVisibility || c.isVisible()) && c.contains(x, y)) {
+                if (c instanceof Container) {
+                    // Calculate the coordinates of the point relative
+                    // to the origin of the container
+                    Point origin = c.getLocation();
+                    return ((Container) c).getComponentAt(x - origin.x, y - origin.y, checkVisibility);
+                } else
+                    return c;
+            }
+        }
+        return null;
+    }
+
     /**
      * Returns the component that contains the specified point, or null
      * if no component contains the point. The x and y coordinates of
      * the point are relative to the origin of this container.
      */
     public Component getComponentAt(Point p) {
-        return getComponentAt(p.x, p.y);
+        return getComponentAt(p.x, p.y, false);
     }
 
     /**
@@ -120,20 +154,27 @@ public abstract class Container
      * the point are relative to the origin of this container.
      */
     public Component getComponentAt(int x, int y) {
-        Enumeration e = _components.elements();
-        while (e.hasMoreElements()) {
-            Component c = (Component) e.nextElement();
-            if (c.contains(x, y)) {
-                if (c instanceof Container) {
-                    // Calculate the coordinates of the point relative
-                    // to the origin of the container
-                    Point origin = c.getLocation();
-                    return ((Container) c).getComponentAt(x - origin.x, y - origin.y);
-                } else
-                    return c;
-            }
-        }
-        return null;
+        return getComponentAt(x, y, false);
+    }
+
+    /**
+     * Returns the visible component that contains the specified point,
+     * or null if no visible component contains the point. The x and y
+     * coordinates of the point are relative to the origin of this container.
+     */
+    public final Component findComponentAt(Point p) {
+        return findComponentAt(p.x, p.y);
+    }
+
+    /**
+     * Returns the visible component that contains the specified point,
+     * or null if no visible component contains the point. The x and y
+     * coordinates of the point are relative to the origin of this container.
+     */
+    public final Component findComponentAt(int x, int y) {
+	if (!isRecursivelyVisible())
+	    return null;
+	return(getComponentAt(x, y, true));
     }
 
     /**
