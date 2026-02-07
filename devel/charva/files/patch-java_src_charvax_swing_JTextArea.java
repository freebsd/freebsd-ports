--- java/src/charvax/swing/JTextArea.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charvax/swing/JTextArea.java
@@ -412,6 +412,10 @@ public class JTextArea
         Point tempCaret = null;
         Point caret = _caret;
 
+        int attrib = 0;
+        if (_bold)
+            attrib |= Toolkit.A_BOLD;
+
         /* Get the absolute origin of this component.
          */
         Point origin = getLocationOnScreen();
@@ -458,7 +462,7 @@ public class JTextArea
                             _rows++;
                         term.setCursor(origin.addOffset(col, row));
                     } else {
-                        term.addChar(chr, 0, colorpair);
+                        term.addChar(chr, attrib, colorpair);
                         col++;
                     }
                 } else {	// We have reached the right-hand column.
@@ -470,7 +474,7 @@ public class JTextArea
                                 _rows++;
                             term.setCursor(origin.addOffset(col, row));
                         } else {
-                            term.addChar(chr, 0, colorpair);
+                            term.addChar(chr, attrib, colorpair);
                             col++;
                             _columns++;
                         }
@@ -482,7 +486,7 @@ public class JTextArea
                                 _rows++;
                             term.setCursor(origin.addOffset(col, row));
                             if (chr != '\n')    // thanks to Chris Rogers for this
-                                term.addChar(chr, 0, colorpair);
+                                term.addChar(chr, attrib, colorpair);
                         } else {
                             /* We must back-track until we get to whitespace, so
                              * that we can move the word to the next line.
