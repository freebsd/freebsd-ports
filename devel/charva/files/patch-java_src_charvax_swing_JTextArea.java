--- java/src/charvax/swing/JTextArea.java.orig	Fri Dec 30 16:14:22 2005
+++ java/src/charvax/swing/JTextArea.java	Mon Jan 29 09:39:30 2007
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
