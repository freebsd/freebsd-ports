--- java/src/charvax/swing/JPasswordField.java.orig	Sat Dec 17 15:27:30 2005
+++ java/src/charvax/swing/JPasswordField.java	Mon Jan 29 09:39:30 2007
@@ -133,8 +133,10 @@ public class JPasswordField
          * UNDERLINE attribute.
          */
         int attrib = 0;
-        if (super._enabled)
+        if (_enabled)
             attrib |= Toolkit.A_UNDERLINE;
+        if (_bold)
+            attrib |= Toolkit.A_BOLD;
 
         term.setCursor(origin);
         term.addString(_padding, attrib, colorpair);
