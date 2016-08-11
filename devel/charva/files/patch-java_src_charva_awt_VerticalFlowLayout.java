--- java/src/charva/awt/VerticalFlowLayout.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charva/awt/VerticalFlowLayout.java
@@ -0,0 +1,229 @@
+/* class FlowLayout
+ *
+ * Copyright (C) 2001  R M Pitman
+ * Copyright (C) 2007  Lapo Luchini
+ *
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2.1 of the License, or (at your option) any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with this library; if not, write to the Free Software
+ * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+ */
+
+package charva.awt;
+
+import java.util.Enumeration;
+import java.util.Vector;
+
+/**
+ * A concrete implementation of LayoutManager that lays out its
+ * components top-to-bottom.
+ */
+public class VerticalFlowLayout
+        implements LayoutManager {
+    /**
+     * Default constructor. Sets alignment to MIDDLE, hgap to 1,
+     * and vgap to 0.
+     */
+    public VerticalFlowLayout() {
+        this(MIDDLE, 1, 0);
+    }
+
+    /**
+     * Use this constructor when you want to set the alignment and the
+     * horizontal and vertical gaps.
+     */
+    public VerticalFlowLayout(int align_, int hgap_, int vgap_) {
+        _align = align_;
+        _hgap = hgap_;
+        _vgap = vgap_;
+    }
+
+    /**
+     * Sets the alignment for this layout. Allowable values are
+     * VerticalFlowLayout.TOP, VerticalFlowLayout.MIDDLE and
+     * VerticalFlowLayout.BOTTOM.
+     */
+    public void setAlignment(int align_) {
+        _align = align_;
+    }
+
+    /**
+     * Gets the alignment for this layout.
+     */
+    public int getAlignment() {
+        return _align;
+    }
+
+    /**
+     * Calculate the minimum-size rectangle that can enclose all the
+     * components in the given container.
+     */
+    public Dimension minimumSize(Container container_) {
+
+        int width = 0;
+        int height = 0;
+
+        Component[] components = container_.getComponents();
+        for (int i = 0; i < components.length; i++) {
+            Dimension d = components[i].minimumSize();
+
+            /* Make allowance for the gap between this component and the
+             * previous component.
+             */
+            if (i != 0)
+                height += _vgap;
+
+            height += d.height;
+            if (d.width > width)
+                width = d.width;
+        }
+
+        /* Take into account the border frame (if any).
+         */
+        Insets insets = container_.getInsets();
+        height += insets.top + insets.bottom;
+        width += insets.left + insets.right;
+
+        return new Dimension(width, height);
+    }
+
+    /**
+     * Lay out the components according to the specified alignment, hgap
+     * and vgap.
+     * This is called when the size of the container has already been
+     * calculated.
+     * It lays out the components in a column, one at a time, until it
+     * determines that there is not enough space left in the column.
+     * Then it moves to the next row. If there is not enough horizontal
+     * space in the container to lay out all of the components, it
+     * removes the remaining components from the container; they don't
+     * appear at all.
+     */
+    public void doLayout(Container container_) {
+
+        Insets insets = container_.getInsets();
+        int availableHeight = container_.getSize().height -
+                insets.top - insets.bottom;
+        int heightLeft = availableHeight;
+        int widthLeft = container_.getSize().width -
+                insets.left - insets.right;
+
+        int hoffset = insets.left;
+
+        Component[] components = container_.getComponents();
+        Vector localvector = new Vector();
+        for (int i = 0; i < components.length; i++) {
+            Component c = components[i];
+
+            /* Get the contained container to lay itself out at its
+             * preferred size, if it is not already laid out.
+             */
+            if (c instanceof Container) {
+                Container cont = (Container) c;
+                if (cont.isValid() == false) {
+                    cont.setSize(cont.minimumSize());
+                    cont.doLayout();
+                }
+            }
+
+            /* Determine the width required to lay out the current
+             * component (including the gap between this component and
+             * the previous component).
+             */
+            int requiredHeight = c.getSize().height;
+            if (i != 0)
+                requiredHeight += _vgap;
+
+            if (requiredHeight > heightLeft) {
+                int columnWidth = 0;
+                if (localvector.size() != 0) {
+                    columnWidth = layoutColumn(container_, localvector,
+                            widthLeft, heightLeft, hoffset);
+                    localvector.removeAllElements();
+                }
+                hoffset += columnWidth + _hgap;
+                heightLeft = availableHeight;
+                widthLeft -= columnWidth + _hgap;
+            }
+            heightLeft -= requiredHeight;
+
+            // Build up a temporary list of components for this row.
+            localvector.add(c);
+        }
+        layoutColumn(container_, localvector, widthLeft, heightLeft, hoffset);
+
+    }
+
+    /**
+     * private function to layout a single column of components.
+     *
+     * @return The height of the laid-out column.
+     */
+    private int layoutColumn(Container container_, Vector components_,
+                          int widthleft_, int heightleft_, int hoffset_) {
+
+        int voffset = 0;
+        int columnWidth = 0;
+        Insets insets = container_.getInsets();
+
+        switch (_align) {
+            case TOP:
+                voffset = insets.top;
+                break;
+            case MIDDLE:
+                voffset = insets.top + heightleft_ / 2;
+                break;
+            case BOTTOM:
+                voffset = insets.top + heightleft_;
+                break;
+        }
+
+        Enumeration e = components_.elements();
+        while (e.hasMoreElements()) {
+            Component c = (Component) e.nextElement();
+            if (c.getSize().width > columnWidth)
+        	columnWidth = c.getSize().width;
+
+            if (columnWidth > widthleft_) {
+                container_.remove(c);	// we have run out of space
+                continue;
+            }
+
+            c.setLocation(hoffset_, voffset);
+            voffset += c.getSize().height + _vgap;
+        }
+        return columnWidth;
+    }
+
+    //====================================================================
+    // INSTANCE VARIABLES
+
+    /**
+     * Alignment of components (TOP, BOTTOM or MIDDLE)
+     */
+    private int _align = MIDDLE;
+
+    /**
+     * Horizontal gap between components
+     */
+    private int _hgap = 1;
+
+    /**
+     * Vertical gap between components
+     */
+    private int _vgap = 0;
+
+    public static final int TOP = 1;
+    public static final int MIDDLE = 2;
+    public static final int BOTTOM = 3;
+
+}
