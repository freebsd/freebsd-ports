--- java/src/charvax/swing/JPasswordField.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charvax/swing/JPasswordField.java
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
