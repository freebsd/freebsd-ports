--- java/src/charvax/swing/JLabel.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charvax/swing/JLabel.java
@@ -20,6 +20,7 @@
 package charvax.swing;
 
 import charva.awt.Dimension;
+import charva.awt.Font;
 import charva.awt.Insets;
 import charva.awt.Point;
 import charva.awt.Toolkit;
@@ -79,6 +80,10 @@ public class JLabel
         // Draw the border if it exists
         super.draw();
 
+        int attrib = 0;
+        if (_bold)
+            attrib |= Toolkit.A_BOLD;
+
         /* Get the absolute origin of this component.
          */
         Point origin = getLocationOnScreen();
@@ -98,7 +103,7 @@ public class JLabel
             buf.setLength(_width);	// truncate
 
         int colorpair = getCursesColor();
-        term.addString(buf.toString(), 0, colorpair);
+        term.addString(buf.toString(), attrib, colorpair);
     }
 
     /**
@@ -169,10 +174,16 @@ public class JLabel
         return "JLabel: [" + getText() + "]";
     }
 
+    public void setFont(Font font_) {
+        _bold = ((font_.getStyle() & Font.BOLD) != 0);
+    }
+
     //====================================================================
     // INSTANCE VARIABLES
 
     private String _labeltext;
     private int _width;
 
+    protected boolean _bold = false;
+
 }
